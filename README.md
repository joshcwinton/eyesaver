# EyeSaver
Arduino based timer that tells me to rest my eyes 😵‍💫

## Problem
I created this because I've been spending much more time looking at digital devices, especially for work. I've come across apps on my phone that remind me to take breaks but I feel that these are often counterproductive for me because I try to avoid using my phone while I'm trying to focus,

## Solution
As a solution, I decided that an independent embedded system would give me a way to remind myself breaks without being distracted. In it's current form, the system starts a 20 minute work timer as soon as it starts up and then gives me a 5 minute break, then loops. Pressing the pushbutton skips the current session and goes straight to the next one.

## Components
- Arduino Uno
- 128x64 Yellow/Blue SSD1306 I2C Display
- Jumper cables
- Power supply
- Pushbutton
- Resistor

# TODO
- [ ] Create an enclosure
- [x] Add buttons to allow reset/skip
- [ ] Add buttons to adjust time increments


# Images
## Start of a Work Session
![Eyesaver-5](https://user-images.githubusercontent.com/29495809/157685409-0db8e042-30bf-4aab-8d8a-12ed041b9da7.jpg)

## Work Countdown
![Eyesaver-1](https://user-images.githubusercontent.com/29495809/157685391-bc1943bb-8c12-4468-955b-5858590d6cbb.jpg)
![Eyesaver-2](https://user-images.githubusercontent.com/29495809/157685394-b8d44236-fd27-47e7-b7e5-6470a38f2716.jpg)

## Break Countdown
![Eyesaver-1-2](https://user-images.githubusercontent.com/29495809/157687289-71f47dac-b0ae-48a3-b8a4-e3f4dc3c07a2.jpg)

