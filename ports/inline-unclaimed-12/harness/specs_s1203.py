"""specs_s1203.py - unclaimed-12 batch 3 (docs/20-unclaimed-12.md, claim 3): ZFFPRIVATESTDOBJ::CopyData (tail-jumps to the
base class CopyData through the vtable slot +0x48) and ZTargetObtained2::Command (calls the exe function at 0x59d250 with a
global object; that callee is replaced by a counting stub, serial_stubs.rec, so only the call and its arguments are compared)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S

def _flush_code(c):
    """Drop Unicorn's cached translations for the heap and the exe image after a patch (as area 20 does): a stale
    translation otherwise runs in place of the new stub bytes."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _priv_copy(c):
    # the vtable slot +0x48 of this is a logging stub (the base CopyData); src+0xc points at a block whose dword +0x23
    # equals 0x200482 in half of the cases (the copy of +0x18 is then taken)
    vt = c.emu.logging_vtable('zgeom-base', 0x14, argwords={0x48: 1})
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_, vt)
    src = _rnd(c, 0x40)
    block = _rnd(c, 0x40)
    c.emu.w32(src + 0xc, block)
    c.emu.w32(block + 0x23, 0x200482 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [self_, src]


def _log3(e, r):
    # stands in for 0x59d250 (thiscall, 3 stack args, ret 0xc): logs the object and all three arguments, returns 0
    args = [e.arg32(k) for k in range(3)]
    e.calllog.append(('0x59d250', e.reg('ecx'), tuple(args)))
    e.ret(eax=0, argbytes=12)


def _setup_cmd(c):
    # replace 0x59d250 with a stub that logs the object and its three arguments (serial_stubs.rec logs only the first);
    # the global at 0x7003b8 points at an object whose dword +0x2c15 is the object the call is made on
    ss.patch(c, 0x59d250, c.emu.stub_fn('0x59d250 logger', _log3))
    _flush_code(c)
    base = _rnd(c, 0x3000)
    target = _rnd(c, 0x100)
    c.emu.w32(base + 0x2c15, target)
    c.emu.w32(0x7003b8, base)


def _cmd(c):
    # the argument is compared as a word: a third of the cases match the word exactly, a third match it with high bits
    # set, a third are random dwords
    self_ = _rnd(c, 0x80)
    word = c.rng.randint(0, 0xffff)
    c.emu.w16(self_ + 0x4c, word)
    r = c.rng.random()
    if r < 0.33:
        arg = word
    elif r < 0.66:
        arg = word | (c.rng.getrandbits(16) << 16)
    else:
        arg = c.rng.getrandbits(32)
    return [self_, arg, _rnd(c, 0x20)]


S(0x5a65c0, 'ZFFPRIVATESTDOBJ::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_priv_copy,
  note='unclaimed-12 batch 3; dword +0x18 copied when src->+0xc->+0x23 == 0x200482; then base CopyData (vtable +0x48)')
S(0x5b7a10, 'ZTargetObtained2::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_cmd,
  setup=_setup_cmd, note='unclaimed-12 batch 3; if word arg == word +0x4c: calls 0x59d250 (stubbed, counts) with (global+0x2c15 object, 2, dword +0x48, 1)')
