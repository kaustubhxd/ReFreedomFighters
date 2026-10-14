"""specs_s956.py - area 56 band, claims A15-A18: tail jumps and import calls, modelled as GUESS recording stubs.

A15 (0x5274e0): the object o (0x40 random bytes) has the target address at +0x20 (a recording stub, thiscall, no arguments, returns
a random dword); this (0x40 random) has +0x28 = o. A16 (0x536980): 0x534050 is hooked (a recording stub, thiscall with one argument,
returns a random dword). A17 (0x533c30): the import slot 0x67613c is written to a recording stub (stdcall, one argument); the value
at 0x701b68 is random. A18 (0x533c40): the slot 0x676144 is written to a recording stub (stdcall, two arguments, returns a random
dword, zero in one case in five); the value at 0x701b6c is random. The image is restored per run, so the slot writes are per case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, name, nargs, ret_fn):
    def h(e2, r):
        args = tuple(e2.arg32(k) for k in range(nargs))
        e2.calllog.append((name, e2.reg('ecx')) + args)
        e2.ret(eax=ret_fn(), argbytes=4 * nargs)
    return e_new(c, name, h)


def e_new(c, name, h):
    return c.emu._new_stub(name, h)


def _gen_a15(c):
    rng = c.rng
    tgt = _stub(c, 'T5274e0', 0, lambda: rng.getrandbits(32))
    o = _rnd(c, 0x40)
    c.emu.w32(o + 0x20, tgt)
    this = _rnd(c, 0x40)
    c.emu.w32(this + 0x28, o)
    return [this]


def _gen_a16(c):
    rng = c.rng

    def h(e2, r):
        e2.calllog.append(('T534050', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=rng.getrandbits(32), argbytes=4)

    c.emu.hook(0x534050, h)
    this = _rnd(c, 0x1100)
    return [this, c.rng.getrandbits(32)]


def _gen_a17(c):
    rng = c.rng
    slot_stub = _stub(c, 'Imp67613c', 1, lambda: 0)
    c.emu.w32(0x67613c, slot_stub)
    c.emu.w32(0x701b68, rng.getrandbits(32))
    return []


def _gen_a18(c):
    rng = c.rng
    v = 0 if rng.random() < 0.2 else rng.getrandbits(32)
    slot_stub = _stub(c, 'Imp676144', 2, lambda: v)
    c.emu.w32(0x676144, slot_stub)
    c.emu.w32(0x701b6c, rng.getrandbits(32))
    return []


S(0x5274e0, 'unnamed 0x5274e0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_a15,
  note='unclaimed-56 A15; tail-jump target is a GUESS recording stub (arity 0)')
S(0x536980, 'unnamed 0x536980 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_a16,
  note='unclaimed-56 A16; 0x534050 is a GUESS recording stub (arity 4, main path)')
S(0x533c30, 'unnamed 0x533c30 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen_a17,
  note='unclaimed-56 A17; import slot 0x67613c is a GUESS recording stub')
S(0x533c40, 'unnamed 0x533c40 (unknown) cdecl', 'cdecl', None, ret='al', gen=_gen_a18,
  note='unclaimed-56 A18; import slot 0x676144 is a GUESS recording stub')
