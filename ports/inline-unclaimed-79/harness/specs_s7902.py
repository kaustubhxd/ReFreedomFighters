"""specs_s7902.py - unclaimed-79 batch 2 (docs/20-unclaimed-79.md): ZActor::MoveToMatPos (0x479620). The object is a logging fake
vtable (slots 0x578 two args, 0x2fc returns 0 or 1, 0x628 three args, 0x588 returns 0 or a random dword, 0x62c one arg). The
helper 0x47aad0 is patched to a logging stub. The byte at +0x726, the dword at +0x6ce and +0x64c are random (+0x64c is 0xa about a
third of the time)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

HELPER = 0x47aad0


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _move(c):
    self_ = _rnd(c, 0x900)
    c.emu.w8(self_ + 0x726, c.rng.choice([0, 1]))
    c.emu.w32(self_ + 0x6ce, c.rng.choice([0, c.rng.getrandbits(32)]))
    c.emu.w32(self_ + 0x64c, c.rng.choice([0xa, 0, c.rng.getrandbits(32)]))
    vs = c.emu.fake_vtable('ZActor-move', 0x18c, {
        0x578: logged_slot('ZActor::slot578', eax=0, argbytes=8),
        0x2fc: logged_slot('ZActor::slot2fc', eax=c.rng.choice([0, 1]), argbytes=0),
        0x628: logged_slot('ZActor::slot628', eax=0, argbytes=12),
        0x588: logged_slot('ZActor::slot588', eax=c.rng.choice([0, 1, c.rng.getrandbits(32)]), argbytes=0),
        0x62c: logged_slot('ZActor::slot62c', eax=0, argbytes=4),
    })
    c.emu.w32(self_, vs)
    a = _rnd(c, 0x20)
    b = _rnd(c, 0x20)

    def h(e, r):
        e.calllog.append(('ZActor::helper47aad0', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)
    ss.patch(c, HELPER, c.emu.stub_fn('ZActor::helper47aad0', h))
    return [self_, a, b]


S(0x479620, 'ZActor::MoveToMatPos(const float*, const float*) thiscall', 'thiscall', None, ret=None, gen=_move,
  note='unclaimed-79 batch 2; slot 0x578, gate 0x2fc, optional 0x628/0x47aad0/0x588/0x62c, stores three dwords from arg2')
