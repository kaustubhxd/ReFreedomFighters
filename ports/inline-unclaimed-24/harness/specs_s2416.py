"""specs_s2416.py - decomp area 24, batch 2416: four small initialisers.
0x6061f0 MD5Engine_t::reset(): the MD5 state (four dwords at +0..+0xc) and the count words (+0x10, +0x14). void.
0x4e6b30 CMemPool::CMemPool(): two dwords at +0 and +4 cleared; returns this (eax). Constructor.
0x54dbf0 (unnamed): object +0x8021 = 0x711d28, global 0x711d28 = 0x10000, global 0x711d2c = 8. void.
0x53ccb0 (unnamed): globals 0x711b7c, 0x711b90, 0x711d20 = 1. void.
Globals are written by the exe code, so the pilot compares them; the object is random."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _obj(size):
    def gen(c):
        clear_hooks(c)
        return [rnd(c, size)]
    return gen


def _none(c):
    clear_hooks(c)
    return []


S(0x6061f0, 'MD5Engine_t::reset', 'thiscall', None, ret=None, gen=_obj(0x40), note='batch2416')
S(0x4e6b30, 'CMemPool::CMemPool', 'thiscall', None, ret='eax', gen=_obj(0x40), note='batch2416')
S(0x54dbf0, 'GUESS: init of object +0x8021 and globals 0x711d28/0x711d2c', 'thiscall', None, ret=None, gen=_obj(0x8040), note='batch2416')
S(0x53ccb0, 'GUESS: init of globals 0x711b7c, 0x711b90, 0x711d20', 'thiscall', None, ret=None, gen=_obj(0x40), note='batch2416')
