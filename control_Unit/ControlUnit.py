
import numpy as np
import scipy.io.wavfile as wav
from scipy.signal import stft
from pydub import AudioSegment
from pydub.playback import play
from scipy.io import wavfile
# from lyrics_extractor import SongLyrics

class Server:  
    def __init__ (server):
        # Add any Server variables here
        
        print("Server initialized")
        pass

class UI:
    def __init__ (ui):
        # Add any UI variables here
        
        print("UI initialized")
        pass

# Ryk disse klasser til deres respektive filer ^

class ControlUnit:
    def __init__(control_unit):
        # Initialize any necessary variables or parameters here

        control_unit.ui = UI() # Replace with actual UI
        control_unit.server = Server() # Replace with actual server
        pass

# Get functions for the recorded song (PSoC) and the chosen song (DB/Server)
    def get_chosenSongLyrics(self, chosenSong_lyrics="Justin_Bieber_-_Ghost.txt"):
        try:
            with open(chosenSong_lyrics, 'r') as file:
                chosenSong_lyrics = file.read()
                return chosenSong_lyrics
        except:
            print("Error: Lyrics not found")
            return None
        # importing modules

    def get_chosenSongMelody(Melody):
        chosenSongMelody = "Justin_Bieber_-_Ghost.wav" # Replace with actual logic
        return chosenSongMelody
    
    def get_recordedSong(recordeding):
        recordedSong = "recording.wav"  # Replace with actual logic
        return recordedSong

# Play the song
    def play_song(get_chosenSongMelody):
        song = AudioSegment.from_wav(get_chosenSongMelody)
        play(song)

# Processing functions
    def calculate_scores(self, segments_processed, segments_stored):
        # Placeholder: Implement logic to calculate scores based on correlation
        scores = ...  # Replace with actual logic
        return scores

    def get_potential_scores(self):
        # Placeholder: Implement logic to get potential scores from a table or other source
        potential_scores = ...  # Replace with actual logic
        return potential_scores

    def calculate_accumulated_score_diff(self, scores, potential_scores):
        # Placeholder: Implement logic to calculate accumulated score difference
        accumulated_score_diff = ...  # Replace with actual logic
        return accumulated_score_diff

    def round_up(self, value):
        # Placeholder: Implement logic to round up a value to the nearest integer
        rounded_value = ...  # Replace with actual logic
        return rounded_value

    def store_integer_score(self, final_score_integer):
        # Placeholder: Implement logic to store the final integer score
        # For example, you might store it in a database or print it
        print("Final Score:", final_score_integer)


    def process_and_store_score(self):
        # Step 1: Input Signals
        processed_signal = self.get_processed_signal()
        stored_signal = self.get_stored_signal()

        # Step 2: Segmentation (STFT)
        segments_processed = self.stft_segmentation(processed_signal)
        segments_stored = self.stft_segmentation(stored_signal)

        # Step 3: Correlation and Scoring
        scores = self.calculate_scores(segments_processed, segments_stored)

        # Step 4: Potential Scores and Accumulation
        potential_scores = self.get_potential_scores()
        accumulated_score_diff = self.calculate_accumulated_score_diff(scores, potential_scores)

        # Step 5: Final Score Calculation
        final_score_percentage = 100 - accumulated_score_diff
        final_score_integer = self.round_up(final_score_percentage)

        # Step 6: Integer Storage
        self.store_integer_score(final_score_integer)