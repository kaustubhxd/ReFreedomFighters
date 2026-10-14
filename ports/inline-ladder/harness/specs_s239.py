"""specs_s239.py - ladder thread batch 239: ZFFHERO::GetMoveSpeeds and GetCrouch."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _h(c):
    return K.rnd(c, 0x900)


S(0x591f30, 'ZFFHERO::GetMoveSpeeds', 'thiscall', None, ret=None,
  gen=lambda c: [_h(c), K.rnd(c, 0x20)], note='batch239')
S(0x483f00, 'ZFFHERO::GetCrouch', 'thiscall', None, ret='al', gen=lambda c: [_h(c)], note='batch239')
