"""specs_s310.py - unclaimed-43 batch 310: ZPlayer::CreateMovementGuide() (0x4829e0), thiscall, no arguments.
new(0x3bf) goes through __builtin_new (0x41e290): the global object 0x70038c is NULL, so the CRT malloc import is used,
stubbed here with a fake-heap block (as in batch 303). The ZMovementGuide constructor (0x4877a0, original code) runs on
that block; its base constructor (0x4876e0) and member constructors write the fields. The allocation fails in 10% of
cases (the malloc stub returns NULL), which skips the constructor."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


FAIL = [False]   # set in gen, read by the stub at call time


def _stub_malloc(c):
    def h(em, rr):
        em.ret(eax=0 if FAIL[0] else em.alloc(max(em.arg32(0), 4), 16), argbytes=0)
    c.emu.stub_import('malloc', h)


def _gen(c):
    FAIL[0] = c.rng.random() < 0.1
    self_ = E.zero_obj(c, 0x40)
    E.set_global(c, 0x70038c, 0)
    c.emu.mu.ctl_flush_tb()
    return [self_]


S(0x4829e0, 'ZPlayer::CreateMovementGuide()', 'thiscall', None, ret=None, gen=_gen, setup=_stub_malloc,
  note='unclaimed-43 batch 310; ZMovementGuide ctor 0x4877a0 and its bases are original exe code')
