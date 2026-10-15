"""specs_s200006.py - Sonnet-w2 batch 200006: SEH-framed ctor / deleting-dtor shapes. Hooked callees record the SEH chain and the object's
vtable word at call time; fake outer SEH records 0-2; fs:[0] compared after return."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def _side(c, o):
    sr = seh_record(c, 2)

    def side(emu, k):
        emu.calllog.append(('vt', emu.r32(o)))
        sr(emu, k)
    return side


def _setup(c, size=0x60):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    return c.rng, rnd(c, size)


def _flags(r):
    return r.choice([0, 1, 2, 3, 0x100, 0xffffffff, r.getrandbits(32)])


def _dd(c, member):
    r, o = _setup(c)
    hook_rec(c, member, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x634273, 2, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    return r, o


def g616c50(c):
    r, o = _dd(c, 0x659c00)
    return [o, _flags(r)]


def g616d60(c):
    r, o = _dd(c, 0x659bb0)
    return [o, _flags(r)]


def g603600(c):
    r, o = _dd(c, 0x603900)
    hook_rec(c, 0x41e2c0, 1, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    return [o, _flags(r)]


def g5c4580(c):
    r, o = _setup(c, 0x1c0)
    hook_rec(c, 0x41e2c0, 1, ret=r.getrandbits(32), pop=0, side=_side(c, o))
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    t = obj(c, 0x40, {0x34: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_side(c, o))}, nslots=0x14)
    c.emu.w32(eng + 0x9b, t)
    return [o]


def g500990(c):
    r, o = _setup(c)
    hook_rec(c, 0x5044c0, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    c.emu.w32(0x700e70, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [o, r.getrandbits(32)]


def g606ce0(c):
    r, o = _setup(c)
    hook_rec(c, 0x5fb600, 0, ret=r.getrandbits(32), this=True, side=_side(c, o))
    hook_rec(c, 0x54f870, 2, ret=r.getrandbits(32), pop=8, side=seh_record(c, 2))
    begin = r.choice([0, rnd(c, 16), r.getrandbits(32)])
    k = r.random()
    if k < 0.25:
        end = begin
    elif k < 0.4:
        end = (begin - r.randrange(1, 64)) & 0xffffffff
    else:
        end = (begin + r.randrange(0, 300)) & 0xffffffff
    c.emu.wbytes(o + 3, begin.to_bytes(4, 'little'))
    c.emu.wbytes(o + 0xb, end.to_bytes(4, 'little'))
    return [o]


S(0x616c50, 'GUESS deleting dtor 14b', 'thiscall', None, ret='eax', gen=g616c50, note='batch200006')
S(0x616d60, 'GUESS deleting dtor 34', 'thiscall', None, ret='eax', gen=g616d60, note='batch200006')
S(0x603600, 'GUESS deleting dtor 18', 'thiscall', None, ret='eax', gen=g603600, note='batch200006')
S(0x5c4580, 'GUESS dtor register', 'thiscall', None, ret='eax', gen=g5c4580, note='batch200006')
S(0x500990, 'GUESS ctor refcounted', 'thiscall', None, ret='eax', gen=g500990, note='batch200006')
S(0x606ce0, 'GUESS dtor vector member', 'thiscall', None, ret='eax', gen=g606ce0, note='batch200006')
