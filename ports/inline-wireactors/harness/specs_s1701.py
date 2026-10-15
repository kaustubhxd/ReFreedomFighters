"""specs_s1701.py - wire-actors thread: ZCamHelper::AngleToAimXZ 0x5cf5d0, same generator as the 0x5cf520 spec (specs_s50._angle)."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from specs_s50 import _angle

S(0x5cf5d0, 'ZCamHelper aim angle to point (XZ)', 'thiscall', None, ret='st0', gen=_angle, note='wire-actors; vangle as exe code')
