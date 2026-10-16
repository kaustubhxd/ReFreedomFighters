"""specs_s232.py - ladder thread batch 232: ZLNKWHANDS::ResetTargets / RemoveTargets (thunk to an empty function)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K

S(0x44a1f0, 'ZLNKWHANDS::ResetTargets (thunk)', 'thiscall', None, ret=None,
  gen=lambda c: [K.rnd(c, 0x40)], note='batch232')
