"""specs_s615.py - damage batch 615: DistanceBoxAndPoint (PC 0x4e2120). The CRT sqrt runs as the harness stub."""
from pilot import S
from wkit import fedge


def _gen(c):
    r = c.rng
    p = c.emu.alloc(16, 4)
    s = c.emu.alloc(16, 4)
    for i in range(3):
        c.emu.wf32(s + 4 * i, r.choice((r.uniform(0, 300), 0.0, 50.0, fedge(c))))
        c.emu.wf32(p + 4 * i, r.choice((r.uniform(-500, 500), r.uniform(-60, 60), 50.0, -50.0, 0.0, fedge(c))))
    return [p, s]


S(0x4e2120, 'DistanceBoxAndPoint', 'fastcall', ret='st0', gen=_gen)
