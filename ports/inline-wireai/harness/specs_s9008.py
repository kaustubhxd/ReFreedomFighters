"""specs_s9008.py - wire-ai batch 9008: CRagdoll2::HandleCalcMatsMsg 0x6421a0 (the ragdoll pose read-out). The ragdoll (+0x17f -> +0xf)
has 16 particle records (0x34, position at +0xc) that are random, near each other, sometimes coincident (zero vectors skip the inlined
vnorm) or far apart (|cos| > 1 into the clamps / max(0, ...)); the bone indices +0x183 ... are distinct and in range (the exe writes a done
flag per index without a check), the five child links sometimes -1. The engine [0x70039c] +0x1aa3 -> +0x18 is a fake skeleton with slot 0xc0
(bind rotations, 9 floats per bone) and slot 0xc4 (bone records 0x30, parent at +0xc: -1, any bone, or itself); both log the model id
([[+0x36]+8]+0x6c). The link (+0x36) slot 0x94 logs the bone's 12 floats. The bind frames (+0x32), the bone buffer (the argument) and the
bone count (+0x26, at most 0x60) are random. Every vector / matrix helper runs as exe code."""
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import nostk

OFFS = [0x183 + 4 * k for k in range(23)]
LINKS = {0x18b, 0x18f, 0x193, 0x197, 0x1a7}


def _hcm(c):
    e, r = c.emu, c.rng
    log = lambda name, off, args: e.calllog.append((name, off, None, tuple(nostk(a) for a in args)))
    n = r.choice([24, 30, 40, 0x40, 0x60, r.randint(23, 0x60)])
    model = r.getrandbits(32)

    def fl(lo, hi):
        return f32(r.uniform(lo, hi))

    def fbuf(cnt, gen):
        a = e.alloc(4 * cnt + 32, 4)
        for i in range(cnt + 8):
            e.wf32(a + 4 * i, gen())
        return a
    rot = fbuf(n * 9, lambda: fl(-1.5, 1.5))
    recs = _rnd(c, n * 0x30 + 32)
    for i in range(n):
        p = r.choice([-1, -1, r.randrange(n), r.randrange(max(i, 1)), i])
        e.w32(recs + i * 0x30 + 0xc, p & 0xffffffff)

    def ret_tab(off, val):
        def h(em, rr):
            log('skel', off, (em.arg32(0),))
            em.ret(eax=val, argbytes=4)
        return h
    sk = _rnd(c, 0x20)
    e.w32(sk, e.fake_vtable('skel', 0xd0 // 4, {0xc0: ret_tab(0xc0, rot), 0xc4: ret_tab(0xc4, recs)}))
    rs = _rnd(c, 0x40)
    e.w32(rs + 0x18, sk)
    eng = _rnd(c, 0x1c00)
    e.wbytes(eng + 0x1aa3, struct.pack('<I', rs))
    e.w32(0x70039c, eng)

    def link94(em, rr):
        m, p = em.arg32(0), em.arg32(1)
        log('link', 0x94, (m, p) + struct.unpack('<12I', em.rbytes(m, 48)))
        em.ret(eax=0, argbytes=8)
    lk = _rnd(c, 0x20)
    e.w32(lk, e.fake_vtable('link', 0x98 // 4, {0x94: link94}))
    lk8 = _rnd(c, 0x80)
    e.w32(lk8 + 0x6c, model)
    e.w32(lk + 8, lk8)
    self_ = _rnd(c, 0x200)
    e.wbytes(self_ + 0x36, struct.pack('<I', lk))
    e.wbytes(self_ + 0x26, struct.pack('<I', n))
    e.wbytes(self_ + 0x32, struct.pack('<I', fbuf(n * 12, lambda: fl(-2, 2))))
    ix = r.sample(range(n), 23)
    for k, off in enumerate(OFFS):
        v = ix[k]
        if off in LINKS and r.random() < 0.2:
            v = -1
        e.wbytes(self_ + off, struct.pack('<i', v))
    # particles: a body-sized cloud; some coincide, some far
    sc = r.choice([0.3, 1.0, 1.0, 5.0, 100.0])
    base = [fl(-50, 50) for _ in range(3)]
    pts = [[f32(base[k] + r.uniform(-sc, sc)) for k in range(3)] for _ in range(16)]
    if r.random() < 0.25:
        # integer grid: differences with exact zero components (only z set, ...)
        pts = [[f32(float(r.randint(-2, 2))) for k in range(3)] for _ in range(16)]
    if r.random() < 0.35:
        # a hip / thigh almost along the root's (negated) up axis, so the cosine may round above 1
        mid = lambda a, b: [(pts[a][k] + pts[b][k]) * 0.5 for k in range(3)]
        m1, m2 = mid(5, 6), mid(8, 9)
        u = [m1[k] - m2[k] for k in range(3)]
        for top, low in ((8, 12), (9, 13)):
            if r.random() < 0.7:
                kk = r.uniform(0.5, 2.0)
                eps = r.choice([0.0, 1e-7, 1e-6, 1e-5]) * sc
                pts[low] = [f32(pts[top][k] - u[k] * kk + r.uniform(-eps, eps)) for k in range(3)]
    for _ in range(r.choice([0, 0, 0, 1, 2, 4])):
        a, b = r.randrange(16), r.randrange(16)
        pts[a] = list(pts[b])
    if r.random() < 0.05:
        pts[r.randrange(16)][r.randrange(3)] = float('nan')
    pr = _rnd(c, 16 * 0x34 + 16)
    for i, p in enumerate(pts):
        e.wbytes(pr + i * 0x34 + 0xc, struct.pack('<3f', *p))
    rag = _rnd(c, 0x20)
    e.wbytes(rag + 0xf, struct.pack('<I', pr))
    e.wbytes(self_ + 0x17f, struct.pack('<I', rag))
    bones = fbuf(n * 12, lambda: fl(-3, 3))
    return [self_, bones]


S(0x6421a0, 'CRagdoll2::HandleCalcMatsMsg', 'thiscall', None, ret=None, gen=_hcm, note='b9008; skeleton tables / link slot 0x94 are fakes, helpers exe code')
