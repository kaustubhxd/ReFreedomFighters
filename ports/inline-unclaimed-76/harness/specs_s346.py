"""specs_s346.py - gap band, batch 346: 0x612170 (cdecl, no arguments, returns bool). The CPUID result is whatever the harness emulator gives,
the same for both sides."""
from pilot import S


def _gen(c):
    return []


S(0x612170, 'mmx612170 (GUESS)', 'cdecl', None, ret='al', gen=_gen, note='batch346; cpuid leaf 1 EDX bit 23')
