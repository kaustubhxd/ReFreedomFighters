"""specs_s848.py - area 50, batch 848: CFireController::DrawActorsOnFire (0x582aa0).
GetController (0x456b70) and GetCen (0x4daf90) are hooked. The engine (0x70039c) has a vtable with the logger slot
(+0x1c4, returns a float in ST0), and a manager (+0x9b) whose slot +0x58 looks up fake objects by key. Every fake object
has slots +0x80 (matrix + offset), +0x2b4 (int), +0x398 (vector), +0x218 (fire sink, logged). Every key the exe can look
up is in the table, so no null object is reached. Values are chosen at generation time so both runs see the same data."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, install_logger


def _gen(c):
    e, r = c.emu, c.rng
    P = {}          # object address -> its parameters
    keys = {}       # key -> object
    st = {'eng': 0}

    def m58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k))
        e.ret(eax=keys.get(k, 0), argbytes=4)

    def h80(e, rr):
        p0, p1 = e.arg32(0), e.arg32(1)
        pr = P[e.reg('ecx')]
        for i in range(12):
            e.wf32(p0 + 4 * i, pr['m'][i])
        for i in range(3):
            e.wf32(p1 + 4 * i, pr['o'][i])
        e.calllog.append(("fx.80", repr(pr["o"][0])))
        e.ret(eax=0, argbytes=8)

    def h2b4(e, rr):
        pr = P[e.reg('ecx')]
        e.calllog.append(('fx.2b4', e.arg32(0)))
        e.ret(eax=pr['k'], argbytes=4)

    def h398(e, rr):
        k, out = e.arg32(0), e.arg32(1)
        pr = P[e.reg('ecx')]
        vec = pr['v'][0 if k == 4 else 1]
        for i in range(3):
            e.wf32(out + 4 * i, vec[i])
        e.calllog.append(('fx.398', k))
        e.ret(eax=0, argbytes=8)

    def h218(e, rr):
        key, pa, pb, cnt = e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)
        a = [repr(e.rf32(pa + 4 * i)) for i in range(3)]   # repr: NaN compares unequal to itself
        b = [repr(e.rf32(pb + 4 * i)) for i in range(3)]
        e.calllog.append(('fx.218', key, a, b, cnt))
        e.ret(eax=0, argbytes=16)

    def fx():
        o = vt_object(c, 0x40, {0x80: h80, 0x2b4: h2b4, 0x398: h398, 0x218: h218}, nslots=0x100, name='fx')
        P[o] = {'m': [c.fv(-3, 3) for _ in range(12)],
                'o': [c.fv(-2, 2) for _ in range(3)],
                'k': r.choice([3, 5, 0]),
                'v': [[c.fv(-4, 4) for _ in range(3)], [c.fv(-4, 4) for _ in range(3)]]}
        return o

    nkeys = r.randint(1, 3)
    ekeys = []
    for _ in range(nkeys):
        k = r.getrandbits(32) | 1
        ekeys.append(k)
        keys[k] = fx()
    mgr = vt_object(c, 0x40, {0x58: m58}, nslots=0x60, name='mgr')

    vals = [c.fv(-1, 1) for _ in range(16)]

    def eng_log(e, rr):
        i = st['eng']
        st['eng'] += 1
        e.calllog.append(('eng.1c4', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8, st0=vals[i % len(vals)])

    def getctl(e, rr):
        pa, pb = e.arg32(0), e.arg32(1)
        e.calllog.append(('GetController',))
        e.w32(pa, r.choice(ekeys))
        e.w32(pb, r.getrandbits(32))
        e.ret(eax=0, argbytes=8)

    def cen(e, rr):
        out = e.arg32(0)
        for i in range(3):
            e.wf32(out + 4 * i, c.fv(-2, 2))
        e.calllog.append(('GetCen', e.reg('ecx')))
        e.ret(eax=0, argbytes=4)

    only_hooks(c, {0x456b70: getctl, 0x4daf90: cen})
    install_logger(c, nargs=2)
    g = vt_object(c, 0x1b00, {0x1c4: eng_log}, nslots=0x80, name='engine')
    e.w32(g + 0x9b, mgr)
    e.w32(g + 0x40, r.randint(0, 1 << 20))
    e.wf32(g + 0x48, r.choice([0.016, 0.05, 0.5]))
    e.w32(0x70039c, g)

    self = vt_object(c, 0xa80, {}, nslots=0x20, name='firecontroller')
    count = r.randint(0, 3)
    e.w32(self + 0x4c, count)
    for i in range(count):
        ent = self + 0x50 + 0x1c * i
        e.w32(ent, r.choice(ekeys))
        for j in range(3):
            e.wf32(ent + 8 + 4 * j, c.fv(-5, 5))
    e.w32(self + 0x48, r.choice(ekeys + [0x12345679]))
    e.wf32(self + 0xa60, r.choice([r.uniform(-0.3, -0.01), r.uniform(-0.05, -0.001), r.uniform(0.0, 2.0)]))   # bounded: emission runs about 1/0.0267 steps per unit
    return [self]


S(0x582aa0, 'CFireController::DrawActorsOnFire', 'thiscall', None, gen=_gen, note='area50 batch848')
