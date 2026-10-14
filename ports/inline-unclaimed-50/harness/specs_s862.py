"""specs_s862.py - area 50, batch 862: 0x5dcd10 (name GUESS), stdcall (two stack args, ret 8), no result.
The object's vt +0x80 writes a 3x3 frame (9 floats) and a vector (3 floats), both from generation-time values. The engine's
vt +0x1c0 (a logger returning a float in ST0) gives three samples per call from a list fixed at generation time. The
out vector and the object's sub-object (+8) floats at +0x40, +0x44, +0x48 are generated. The exe's 0x451890 is run as is."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    frame = [fin(c.fv(-2, 2)) for _ in range(9)]
    vec = [fin(c.fv(-2, 2)) for _ in range(3)]
    samples = [r.uniform(0.0, 1.0) for _ in range(12)]
    st = {'i': 0}

    def v80(e, rr):
        pm, pb = e.arg32(0), e.arg32(1)
        for i in range(9):
            e.wf32(pm + 4 * i, frame[i])
        for i in range(3):
            e.wf32(pb + 4 * i, vec[i])
        e.calllog.append(('obj.80',))
        e.ret(eax=0, argbytes=8)

    def s1c0(e, rr):
        i = st['i']
        st['i'] += 1
        e.calllog.append(('eng.1c0', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8, st0=samples[i % len(samples)])

    only_hooks(c, {})
    eng = vt_object(c, 0x1b00, {0x1c0: s1c0}, nslots=0x100, name='engine')
    e.w32(0x70039c, eng)
    obj = vt_object(c, 0x40, {0x80: v80}, nslots=0x100, name='obj')
    sub = rnd(c, 0x80)
    for off in (0x40, 0x44, 0x48):
        e.wf32(sub + off, fin(c.fv(-3, 3)))
    e.w32(obj + 8, sub)
    out = rnd(c, 16)
    for i in range(3):
        e.wf32(out + 4 * i, fin(c.fv(-2, 2)))
    return [obj, out]


S(0x5dcd10, 'Fn5dcd10 (GUESS name)', 'stdcall', None, gen=_gen, note='area50 batch862')
