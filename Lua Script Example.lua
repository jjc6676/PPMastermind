-- Initialize PPM channels
local pitch, roll, yaw, throttle = 0, 0, 0, 0

-- Function to process PPM input
function processPPM(ppmData)
  pitch = ppmData[1]
  roll = ppmData[2]
  yaw = ppmData[3]
  throttle = ppmData[4]
end

-- Simulate incoming data
local testPPM = {1500, 1600, 1400, 1700}
processPPM(testPPM)

-- Print the results
print("Pitch: " .. pitch)
print("Roll: " .. roll)
print("Yaw: " .. yaw)
print("Throttle: " .. throttle)
