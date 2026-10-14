"""specs_s35062.py - 0x4238a0 (thiscall(a) ret 4, ret='al'). Session object (0x2700 bytes): vtable slots 0x100, 0x30 (1 arg; AL true in 2/3, garbage upper bytes), 0x38, 0x158; bytes +0x1a9a, +0x25ea, +0x60 each 0 or 1
(non-zero values random bytes); unaligned function pointer at +0x23d6 = a thiscall stub (1 arg); global object at 0x700394 with slot 0; 0x424130 hooked (thiscall, AL true in 2/3)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4238a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    al = lambda p: ((r.getrandbits(24) << 8) | r.choice([1, 2, 0x80])) if r.random() < p else (r.getrandbits(24) << 8)
    hook_rec(c, 0x424130, 0, this=True, ret=al(2 / 3))
    g = obj(c, 0x10, {0: pystub(c, 0, this=True)}, nslots=2)
    e.w32(0x700394, g)
    me = obj(c, 0x2700, {0x100: pystub(c, 1, this=True), 0x30: pystub(c, 1, this=True, ret=al(2 / 3)), 0x38: pystub(c, 0, this=True),
                         0x158: pystub(c, 0, this=True)}, nslots=0x57)
    for off in (0x1a9a, 0x25ea, 0x60):
        e.wbytes(me + off, bytes([0 if r.random() < 0.5 else r.randint(1, 255)]))
    e.wbytes(me + 0x23d6, pystub(c, 1, this=True).to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


S(0x4238a0, 'GUESS start-up state machine step', 'thiscall', None, ret='al', gen=_g4238a0, note='batch35062')
