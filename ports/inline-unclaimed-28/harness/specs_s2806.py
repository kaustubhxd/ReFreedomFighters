"""specs_s2806.py - unclaimed-28 batch 6 (docs/20-unclaimed-28.md): CAction::Command (0x49fdb0). The helpers 0x4a02e0, 0x4a01c0,
0x4a03b0 and 0x4a0d00 are patched to logging stubs for both sides (0x4a0d00 returns a list object with 0 to 3 elements), the
strcmp-like import slot 0x676414 is pointed at a logging cdecl stub that returns 0 or 1, and 0x7003b0 is a logging no-arg
function. The dispatch words at 0x7002ac..0x7002dc are random per case; the command is one of them or random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

WORDS = [0x7002ac, 0x7002d4, 0x7002b4, 0x7002b0, 0x7002b8, 0x7002bc, 0x7002d8, 0x7002dc]


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _patch_fn(c, name, addr, argbytes, eax_fn=None):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(argbytes // 4))
        e.calllog.append((name, e.reg('ecx')) + args)
        e.ret(eax=(eax_fn() if eax_fn else 0), argbytes=argbytes)
    ss.patch(c, addr, c.emu.stub_fn(name, h))


def _cmd(c):
    self_ = _rnd(c, 0x200)
    vs = c.emu.fake_vtable('CAction-vt', 0x24, {0x58: logged_slot('CAction::slot58', eax=0, argbytes=0),
                                                0x0c: logged_slot('CAction::slot0c', eax=0, argbytes=0)})
    c.emu.w32(self_, vs)
    for w in WORDS:
        c.emu.w16(w, c.rng.getrandbits(16))
    cmd = c.rng.choice(WORDS + [c.rng.getrandbits(16)])
    c.emu.w16(self_ + 0x5f, cmd if c.rng.random() < 0.3 else c.rng.getrandbits(16))
    c.emu.w16(self_ + 0x61, cmd if c.rng.random() < 0.2 else c.rng.getrandbits(16))
    c.emu.w8(self_ + 0x63, c.rng.choice([0, 1]))
    c.emu.w8(self_ + 0x5e, c.rng.choice([0, 1, 1]))
    c.emu.w32(self_ + 0x5a, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x102, c.rng.choice([0, c.rng.getrandbits(32)]))
    # list returned by 0x4a0d00: count then element pointers
    n = c.rng.randint(0, 3)
    lst = _rnd(c, 0x40)
    c.emu.w32(lst, n)
    ve = c.emu.fake_vtable('CAction-elem', 0x2c, {0xac: logged_slot('CActionElem::slotac', eax=0, argbytes=0)})
    for k in range(n):
        el = _rnd(c, 0x100)
        c.emu.w32(el, ve)
        c.emu.w32(el + 0x7a, c.rng.getrandbits(32))
        c.emu.w32(lst + 4 + 4 * k, el)
    _patch_fn(c, 'CAction::helper4a02e0', 0x4a02e0, 4)
    _patch_fn(c, 'CAction::helper4a01c0', 0x4a01c0, 4)
    _patch_fn(c, 'CAction::helper4a03b0', 0x4a03b0, 8)
    _patch_fn(c, 'CAction::list4a0d00', 0x4a0d00, 0, eax_fn=lambda: lst)
    # 0x7003b0 holds a function pointer: point it at a logging no-arg stub
    fp = c.emu.stub_fn('CAction::fnptr', lambda e, r: (e.calllog.append(('CAction::fnptr',)), e.ret(eax=0, argbytes=0)))
    c.emu.w32(0x7003b0, fp)
    # the strcmp-like import slot: cdecl, two arguments, returns 0 or 1
    cmp_stub = c.emu.stub_fn('CAction::strcmp', lambda e, r: (e.calllog.append(('CAction::strcmp', e.arg32(0), e.arg32(1))),
                                                             e.ret(eax=c.rng.choice([0, 0, 1]), argbytes=0)))
    c.emu.w32(0x676414, cmp_stub)
    argv = c.rng.choice([0, c.rng.getrandbits(32)])
    return [self_, cmd, argv if argv else c.emu.alloc(4, 4)]


S(0x49fdb0, 'CAction::Command(unsigned short, void*) thiscall', 'thiscall', None, ret='eax', gen=_cmd,
  note='unclaimed-28 batch 6; word dispatch over 8 command words; helpers stubbed; list walk with strcmp import')
