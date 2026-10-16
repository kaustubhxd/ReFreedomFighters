"""specs_s6503.py - unclaimed-65 batch 3 (docs/20-unclaimed-65.md, claim 3): GUESS FUN_6463e0. The object at (global 0x70039c)+0x190f
has slot +0x20 (one arg) returning Y; 0x63ea50 (thiscall, no args) is a per-case stub; when it returns zero, the tail call goes to
R+0x18's slot +0xbc with one argument (a logging fake). Translation cache flushed after the patch."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    from serial_stubs import patch
    import serial_stubs as ss  # noqa: F401
    # 0x63ea50: returns a per-case value (zero in a third of cases)
    ret_val = 0 if c.rng.random() < 0.33 else c.rng.getrandbits(32)

    def ea50(e, r):
        e.calllog.append(('0x63ea50', e.reg('ecx'), ()))
        e.ret(eax=ret_val, argbytes=0)
    patch(c, 0x63ea50, c.emu.stub_fn('0x63ea50', ea50))
    _flush_code(c)

    # Y: the result of X's slot +0x20 (Y is only passed to 0x63ea50 as this)
    y = _rnd(c, 0x40)
    y_vt = c.emu.logging_vtable('fn-y', 0x30)
    c.emu.w32(y, y_vt)
    x_vt = c.emu.logging_vtable('fn-x', 0x30, impl={0x20: lambda e, a: (y, None)}, argwords={0x20: 1})
    x = _rnd(c, 0x40)
    c.emu.w32(x, x_vt)
    # R+0x18: slot +0xbc (one arg) logs and returns a value
    t_vt = c.emu.logging_vtable('fn-tail', 0xc0, argwords={0xbc: 1})
    t = _rnd(c, 0x40)
    c.emu.w32(t, t_vt)
    r = _rnd(c, 0x2000)
    c.emu.w32(r + 0x18, t)
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x190f, x)
    c.emu.w32(rm + 0x1aa3, r)
    c.emu.w32(0x70039c, rm)
    # arg: +8 is an object whose dword +0x6c is the tail argument
    x2 = _rnd(c, 0x80)
    arg = _rnd(c, 0x20)
    c.emu.w32(arg + 8, x2)
    return [_rnd(c, 0x40), arg]   # this (ecx), then the one stack argument


S(0x6463e0, 'GUESS FUN_6463e0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-65 batch 3 (residue 18, GUESS name); X slot 0x20 -> Y; 0x63ea50 zero -> tail to R+0x18 slot 0xbc')
