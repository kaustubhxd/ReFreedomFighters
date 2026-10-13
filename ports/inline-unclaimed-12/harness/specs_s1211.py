"""specs_s1211.py - unclaimed-12 batch 11 (docs/20-unclaimed-12.md, claim 11, in slice): ZRelayMessageList::Command.
The virtual slot +0x64 of this is a logging stub; 0x4b8ab0 is a logging stub; the render-style object at the global 0x70039c
supplies the dword at +0x40. The translation cache is flushed after each patch."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    def call_4b8ab0(e, r):
        e.calllog.append(('0x4b8ab0', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    ss.patch(c, 0x4b8ab0, c.emu.stub_fn('0x4b8ab0 logger', call_4b8ab0))

    def slot64(e, r):
        e.calllog.append(('slot+0x64', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt = c.emu.fake_vtable('relay-list', 0x68, {0x64: slot64})
    rm = _rnd(c, 0x200)
    c.emu.w32(0x70039c, rm)
    c.emu.w32(rm + 0x40, c.rng.getrandbits(32))
    _flush_code(c)
    return vt


def _gen_for(vt):
    def gen(c):
        self_ = _rnd(c, 0x80)
        c.emu.w32(self_, vt)
        word = c.rng.randint(0, 0xffff)
        c.emu.w16(self_ + 0x48, word)
        r = c.rng.random()
        # +0x50: 0.0 in a third (equal), NaN or a value otherwise
        f = 0.0 if r < 0.33 else (float('nan') if r < 0.4 else c.fv(-10.0, 10.0))
        c.emu.wf32(self_ + 0x50, f)
        arg = word if c.rng.random() < 0.5 else c.rng.getrandbits(32)
        return [self_, arg, _rnd(c, 0x20)]
    return gen


def _setup_and_gen(c):
    c._vt = _setup(c)


def _command(c):
    return _gen_for(c._vt)(c)


S(0x4b88f0, 'ZRelayMessageList::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_command,
  setup=_setup_and_gen, note='unclaimed-12 batch 11 (in slice); word match; ordered-equal 0.0 calls 0x4b8ab0, else float +0x54 and slot +0x64')
