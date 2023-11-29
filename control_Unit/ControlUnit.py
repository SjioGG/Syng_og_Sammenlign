#controlUnit
#Max Glintborg Dall & Oliver Kok

import numpy as np
import scipy.io.wavfile as wav
import wave
from pydub import AudioSegment

chosenSong = "Justin_Bieber_-_Ghost"                    #Temporary data, this should be a getFunction, for the string that contains the file name
recordedSong = "recording"                              #Temporary data, this should be a getFunction, for the string that contains the file name
directoryPath = "this/is/a/path/to/a/file.wav"          #Temporary path to the .wav file.

#chosenPath = directoryPath + chosenSong + ".wav"       #Assuming the file is stored as "songName" + ".wav"
#recordedPath = directoryPath + "recordedSong" + ".wav" #Assuming the file is stored as "recordedSong" + ".wav"

path1 = chosenSong + ".wav"                             #This is for testing, correct function is above

class ControlUnit:
    
    #constructor that takes the path to the wav file as input
    def __init__(self, chosenPath, recordedPath):
        self.path = chosenPath              #path to the file.
        rate1, data1 = wav.read(path1)      #read the sampling rate 'rate1' and the .wav data 'data1' from the file
        print("Rate:", rate1)               #prints the sampling rate

