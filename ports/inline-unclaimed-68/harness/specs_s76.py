"""specs_s76.py - unclaimed-68 batch 76 (slice 7). Names GUESS (FUN_addr). Exe helpers run as they are; the CRT sized delete 0x634273
(cdecl) is hooked and logged, not run; the engine global (0x70039c) is an object with random bytes (initScales reads it)."""
from pilot import S
from engine_stubs import zero_obj, set_global


def _setup(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('delete634273', em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=0)))


def _rnd(c, n):
    o = zero_obj(c, n)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return o


def _eng(c):
    eng = _rnd(c, 0x400)
    set_global(c, 0x70039c, eng)


def _g4b9530(c):
    _eng(c)
    o = _rnd(c, 0x200)
    src = _rnd(c, 0x200)
    return [o, src]


def _g4cbec0(c):
    o = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        c.emu.w32(o, o + 4)
    else:
        c.emu.w32(o, c.emu.alloc(16, 4))
    return [o]


def _g4d8430(c):
    _eng(c)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x84, o + 0x88 if c.rng.random() < 0.5 else c.emu.alloc(16, 4))
    c.emu.w32(o + 4, c.emu.alloc(16, 4) if c.rng.random() < 0.5 else o + 8)
    return [o]


def _g4e5ef0(c):
    _eng(c)
    o = _rnd(c, 0x100)
    buf = _rnd(c, 0x40)
    c.emu.w32(o, buf)
    return [o]


def _g5fd630(c):
    _eng(c)
    o = _rnd(c, 0x40)
    base = c.emu.alloc(0x400, 16)
    c.emu.w32(o, base)
    c.emu.w32(o + 4, base + c.rng.randrange(0, 0x100))
    # pair = (B, A) with A >= B, so the length A - B is small and non-negative (the callee moves memory with it)
    pair = c.emu.alloc(8, 4)
    b_val = c.rng.randrange(0, 0x20)
    c.emu.w32(pair, b_val)
    c.emu.w32(pair + 4, b_val + c.rng.randrange(0, 0x20))
    return [o, c.rng.randrange(0, 0x40), c.rng.randrange(0, 0x40), pair]


S(0x4b9530, 'FUN_4b9530 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g4b9530, setup=_setup,
  note='unclaimed-68 batch 76: copies five fields from the argument; calls exe 0x4ba310')
S(0x4cbec0, 'FUN_4cbec0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g4cbec0, setup=_setup,
  note='unclaimed-68 batch 76: delete([this], 1) unless [this] == this+4 (cdecl delete hooked)')
S(0x4d8430, 'FUN_4d8430 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g4d8430, setup=_setup,
  note='unclaimed-68 batch 76: vt = 0x696c14; exe 0x4cbec0 on this+0x84 and this+4')
S(0x4e5ef0, 'FUN_4e5ef0 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_g4e5ef0, setup=_setup,
  note='unclaimed-68 batch 76: bl = exe 0x4e5f10(this) != 0; exe 0x4e6420(this); returns bl')
