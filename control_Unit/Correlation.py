#controlUnit
#Max Glintborg Dall & Oliver Kok

import numpy as np
import scipy.io.wavfile as wav

chosenSong = "Justin_Bieber_-_Ghost"            #Temporary data, this should be a getFunction, for the string that contains the file name
directoryPath = "this/is/a/path/to/a/file.wav"  #Temporary path to the .wav file.
#path = directoryPath + chosenSong + ".wav"     #Assuming the file is stored as "songName" + ".wav"
path1 = chosenSong + ".wav"                      #This is for testing, correct function is above

class ControlUnit:
    
    #constructor that takes the path to the wav file as input
    def __init__(self, path):
        self.path = path               #path to the file.
        rate1, data1 = wav.read(path1) #read the sampling rate 'rate1' and the .wav data 'data1' from the file
        print("Rate:", rate1)          #prints the sampling rate



file1 = "Justin_Bieber_-_Ghost.wav"


# Read audio data
rate1, data1 = wav.read(file1)
print("Rate:", rate1)