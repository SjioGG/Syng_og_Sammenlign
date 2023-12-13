from ControlUnit import ControlUnit
from LogicUnit import LogicUnit

import numpy as np

# Completed tests for ControlUnit class
# Play song: test completed, get functions: completed

# Completed tests for LogicUnit class
# STFT segmentation: test pending, correlation: test pending


# create instance of logicUnit
_LogicUnit_ = LogicUnit()

chosenSegment = _LogicUnit_.audio_segmentation(_LogicUnit_.readAudioFile("justin_bieber_ghost[vocals].wav"))
recordedSegment = _LogicUnit_.audio_segmentation(_LogicUnit_.readAudioFile("cover_justin_bieber_ghost[vocals].wav"))
corr = _LogicUnit_.correlate(recordedSegment, chosenSegment)