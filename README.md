# fm-transmitter
Arduino based auto tuning FM transmitter

Remember the dark ages when cars didn't have AUX inputs or Bluetooth to get music from your phone/iPod to the radio? If you were lucky, you had a cassette player and you used one of those adapters that put a headphone cord into a fake tape. If you were unlucky, like me, your car was too new for a cassette player, but too old for an AUX or Bluetooth. We had to survive with FM transmitters. You plugged one end into the car's cigarette lighter for power, and the 3.5mm jack into your music box. In the middle was an FM transmitter that broadcasted your music on an FM radio station that you would tune into to listen to your music. It wasn't great. The audio quality was nowhere near as good as a CD, but worse, it was always tricky to find an FM frequency with nothing else on it. You just had to guess which one would be best.
I thought I could do better than the multi-million dollar electronics companies though. I got an Arduino, FM transmitter and Motorola 3310 display and put together my own transmitter that automatically tuned to the best station. It's a pretty simple program. It just scans a  frequency and stores its signal strength in a variable. It moves on to the next frequency and gets its signal strength. If this frequency has a signal strength lower than the previous frequency, the new frequency replaces the old one. After scanning all frequencies, it knows which one would be best to transmit your own music on.
It worked alright. The sound quality was still not great, but I never had trouble tuning into a good station again.