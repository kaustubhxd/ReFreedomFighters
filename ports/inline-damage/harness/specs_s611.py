"""specs_s611.py - damage batch 611: CHitpointControl::Command (PC 0x582470). Notify 0x5849d0 patched to a stub."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge, b
from dkit import seq_rec_stub, patch_jmp


def _gen(c):
    r = c.rng
    emu = c.emu
    patch_jmp(c, 0x5849d0, stub(c, 0))
    ids = [r.getrandbits(16) for _ in range(4)]
    for i, v in enumerate(ids):
        emu.wbytes(0x714278 + 4 * i, struct.pack('<H', v))
    msg = r.choice(ids + ids + [r.getrandbits(16)])
    hpc = obj(c, 0x80, {0x64: stub(c, 1), 0x4c: stub(c, 0)})
    emu.wf32(hpc + 0x64, r.choice((100.0, 20.0, 5.0, 0.0, -1.0, fedge(c))))
    emu.wf32(hpc + 0x4c, r.choice((0.0, 0.0, 10.0, 30.0, fedge(c))))
    emu.wf32(hpc + 0x57, r.choice((0.0, 0.0, 1.5, fedge(c))))
    calc = emu.alloc(4, 4)
    emu.wf32(calc, r.choice((20.0, 34.5, 120.0, 0.0, -10.0, fedge(c))))
    tmpl = obj(c, 0x40, {0x35c: stub(c, 2, fld=calc)})
    w = obj(c, 0x100, {0x1e0: stub(c, 1, ret=b(c, 0.3)), 0x350: stub(c, 0, ret=tmpl)})
    ci = rnd(c, 0x40)
    rm = obj(c, 0x200, {0x58: seq_rec_stub(c, 1, [w if r.random() < 0.9 else 0, w, w if r.random() < 0.9 else 0]),
                        0x154: stub(c, 2, ret=ci)})
    eng = rnd(c, 0x200)
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    data = rnd(c, 0x30)
    emu.wf32(data + 0x14, r.uniform(0, 10000))
    emu.wf32(data + 0x28, r.choice((50.0, 10.0, 200.0, -20.0, 0.0, fedge(c))))
    return [hpc, msg | (r.getrandbits(16) << 16), data]


S(0x582470, 'CHitpointControl::Command', 'thiscall', ret='eax', gen=_gen)
