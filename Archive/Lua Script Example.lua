-- Lua Script for FrSky X20S: Touchscreen Flight Mode Selector with Failsafe Mode

-- Initialize PWM channel values
local pitchPWM, rollPWM, yawPWM, throttlePWM = 1500, 1500, 1500, 1500
local pitchGain, rollGain, yawGain = 50, 50, 50 -- Default gain values (0 to 100)
local flightMode = 1 -- Default flight mode (Beginner)
local signalLost = false -- Track signal loss

-- Touchscreen button positions
local modeButtons = {
    {x = 10, y = 30, width = 100, height = 20, label = "Beginner"},
    {x = 10, y = 55, width = 100, height = 20, label = "Intermediate"},
    {x = 10, y = 80, width = 100, height = 20, label = "Expert"}
}

-- Function to read PWM inputs
local function readPWM(channel)
    local pwmValue = model.getPWM(channel)
    if pwmValue == nil then
        signalLost = true  -- Enable failsafe mode if signal is lost
        return 1500        -- Default safe value (neutral)
    else
        signalLost = false
        return pwmValue
    end
end

-- Function to write PWM outputs to servos
local function writePWM(channel, value)
    model.setPWM(channel, value) -- Sends adjusted PWM signals
end

-- Function to update gains
local function updateSettings()
    pitchGain = math.floor(getValue("ls1") * 100)
    rollGain = math.floor(getValue("ls2") * 100)
    yawGain = math.floor(getValue("ls3") * 100)
end

-- Function to activate failsafe mode if signal is lost
local function failsafe()
    if signalLost then
        flightMode = 1  -- Force Beginner Mode for safety
        pitchPWM, rollPWM, yawPWM, throttlePWM = 1500, 1500, 1500, 1000 -- Neutral values, throttle idle
    end
end

-- Function to draw touchscreen buttons and highlight selection
local function drawFlightModeSelector()
    lcd.clear()
    lcd.drawText(10, 10, "Select Flight Mode:", 0)

    for i, btn in ipairs(modeButtons) do
        if flightMode == i then
            lcd.drawFilledRectangle(btn.x, btn.y, btn.width, btn.height) -- Highlight selected mode
            lcd.drawText(btn.x + 5, btn.y + 5, btn.label, INVERS)
        else
            lcd.drawRectangle(btn.x, btn.y, btn.width, btn.height) -- Draw non-selected button
            lcd.drawText(btn.x + 5, btn.y + 5, btn.label, 0)
        end
    end

    -- Display failsafe warning if signal is lost
    if signalLost then
        lcd.drawText(10, 110, "SIGNAL LOST - FAILSAFE!", BLINK + INVERS)
    end
end

-- Function to detect touchscreen taps and change flight mode
local function checkTouchInput(event)
    local x, y = getTouchPos() -- Get touch position
    if x and y then
        for i, btn in ipairs(modeButtons) do
            if x >= btn.x and x <= btn.x + btn.width and y >= btn.y and y <= btn.y + btn.height then
                flightMode = i -- Change flight mode based on touch input
            end
        end
    end
end

-- Main loop function
local function run(event)
    -- Read PWM inputs
    pitchPWM = readPWM(1)
    rollPWM = readPWM(2)
    yawPWM = readPWM(3)
    throttlePWM = readPWM(4)

    -- Update settings and check failsafe
    updateSettings()
    failsafe()

    -- Adjust PWM values based on gain settings
    pitchPWM = pitchPWM + (pitchGain - 50) * 10
    rollPWM = rollPWM + (rollGain - 50) * 10
    yawPWM = yawPWM + (yawGain - 50) * 10

    -- Write adjusted PWM signals to servos
    writePWM(1, pitchPWM)
    writePWM(2, rollPWM)
    writePWM(3, yawPWM)
    writePWM(4, throttlePWM)

    -- Check for touchscreen input
    checkTouchInput(event)

    -- Draw the flight mode selector with touchscreen buttons
    drawFlightModeSelector()
end

return { run = run }
