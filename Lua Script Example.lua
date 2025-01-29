-- Lua Script for FrSky X20S: PWM Control with Graphical Flight Mode Selector and Failsafe Mode

-- Initialize PWM channel values
local pitchPWM, rollPWM, yawPWM, throttlePWM = 1500, 1500, 1500, 1500
local pitchGain, rollGain, yawGain = 50, 50, 50 -- Default gain values (0 to 100)
local flightMode = 1 -- Default flight mode (Beginner)
local signalLost = false -- Track signal loss

-- Function to read PWM inputs
local function readPWM(channel)
    local pwmValue = model.getPWM(channel) -- Reads real PWM input from the receiver
    if pwmValue == nil then
        signalLost = true  -- Set failsafe if signal is lost
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

-- Function to update gains and flight mode
local function updateSettings()
    -- Adjust gains using sliders
    pitchGain = math.floor(getValue("ls1") * 100) -- Slider 1 for pitch gain
    rollGain = math.floor(getValue("ls2") * 100)  -- Slider 2 for roll gain
    yawGain = math.floor(getValue("ls3") * 100)   -- Slider 3 for yaw gain

    -- Flight mode switch (3-position switch "sa")
    local modeSwitch = getValue("sa") 
    if modeSwitch < 0 then
        flightMode = 1 -- Beginner Mode
    elseif modeSwitch == 0 then
        flightMode = 2 -- Intermediate Mode
    else
        flightMode = 3 -- Expert Mode
    end
end

-- Function to activate failsafe mode on signal loss
local function failsafe()
    if signalLost then
        flightMode = 1  -- Force Beginner Mode for safety
        pitchPWM, rollPWM, yawPWM, throttlePWM = 1500, 1500, 1500, 1000 -- Neutral values, throttle idle
    end
end

-- Function to draw graphical flight mode selector
local function drawFlightModeSelector()
    lcd.clear()
    lcd.drawText(10, 10, "Flight Mode:", 0)

    -- Draw selection box
    if flightMode == 1 then
        lcd.drawFilledRectangle(10, 30, 100, 20) -- Highlight Beginner
        lcd.drawText(15, 35, "Beginner", INVERS)
    else
        lcd.drawText(15, 35, "Beginner", 0)
    end

    if flightMode == 2 then
        lcd.drawFilledRectangle(10, 50, 100, 20) -- Highlight Intermediate
        lcd.drawText(15, 55, "Intermediate", INVERS)
    else
        lcd.drawText(15, 55, "Intermediate", 0)
    end

    if flightMode == 3 then
        lcd.drawFilledRectangle(10, 70, 100, 20) -- Highlight Expert
        lcd.drawText(15, 75, "Expert", INVERS)
    else
        lcd.drawText(15, 75, "Expert", 0)
    end

    -- Display failsafe warning if signal is lost
    if signalLost then
        lcd.drawText(10, 100, "SIGNAL LOST - FAILSAFE!", BLINK + INVERS)
    end
end

-- Main loop function
local function run(event)
    -- Read PWM inputs
    pitchPWM = readPWM(1) -- Channel 1
    rollPWM = readPWM(2)  -- Channel 2
    yawPWM = readPWM(3)   -- Channel 3
    throttlePWM = readPWM(4) -- Channel 4

    -- Update settings
    updateSettings()
    failsafe() -- Activate failsafe if needed

    -- Adjust PWM values based on gain settings
    pitchPWM = pitchPWM + (pitchGain - 50) * 10
    rollPWM = rollPWM + (rollGain - 50) * 10
    yawPWM = yawPWM + (yawGain - 50) * 10

    -- Write adjusted PWM signals to servos
    writePWM(1, pitchPWM)
    writePWM(2, rollPWM)
    writePWM(3, yawPWM)
    writePWM(4, throttlePWM)

    -- Draw the graphical flight mode selector
    drawFlightModeSelector()
end

return { run = run }
