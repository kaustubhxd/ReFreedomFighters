"""specs_s852.py - area 50, batch 852: 0x4aea10 (name GUESS), thiscall, no args.
The table at [0x7003b8]: count at +4, entry pointers from +8. Each entry has a sub-object (+8, flag 0x1000 at +0x3c, mostly
set), a byte at +0x776 (mostly set), and a timer at +0x624. Its vt +0x438 and +0x2fc are answers (mostly false); its vt
+0x57c writes two vectors (B = arg0, A = arg1) from a list fixed at generation time. The pair test 0x4ae5a0 is stood in:
it logs its two records (key float at +0 and the object at +0x30), answers true at most 20 times per case (the list
is kept short, as the exe's stack list is; the answers favour pairs that touch the first three entries), and sometimes sets a record's flag at +0x34 (the exe's flag use is then exercised). The sort 0x4ae3e0 runs as exe code. The engine has dt at +0x48."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    keyset = [-120.0, -60.0, 0.0, 60.0, 120.0]       # 60 apart: a key can equal another key + 60 (the phase-2 test)
    def key():
        q = r.random()
        if q < 0.04:
            return float('nan')                      # NaN keys: the comparisons then go the other way (jae not taken)
        if q < 0.45:
            return r.choice(keyset)
        return fin(c.fv(-150, 150))
    vecs = [key() for _ in range(600)]
    st = {'v': 0, 'call': 0}
    objidx = {}                       # object address -> table index (the same in both runs)
    picks = [r.random() for _ in range(400)]
    st['budget'] = 0
    marks = {i: r.choice([0, 1]) for i in r.sample(range(300), 80)}   # calls that flag record A or B (the flag at +0x34)

    def nv():
        v = vecs[st['v'] % len(vecs)]
        st['v'] += 1
        return v

    def ans(p):
        def h(e, rr):
            e.calllog.append(('ent.call', p))
            e.ret(eax=1 if p else 0, argbytes=0)
        return h

    def v57c(e, rr):
        pb, pa = e.arg32(0), e.arg32(1)
        for i in range(3):
            e.wf32(pb + 4 * i, nv())
        for i in range(3):
            e.wf32(pa + 4 * i, nv())
        e.calllog.append(('ent.57c',))
        e.ret(eax=0, argbytes=8)

    def pairtest(e, rr):
        ra, rb = e.arg32(0), e.arg32(1)
        i = st['call']
        st['call'] += 1
        e.calllog.append(('pair', e.reg('ecx'), repr(e.rf32(ra)), e.r32(ra + 0x30),
                          repr(e.rf32(rb)), e.r32(rb + 0x30)))
        if i in marks:
            e.w8(ra + 0x34 if marks[i] else rb + 0x34, 1)     # the test marks one record as used
        ia, ib = objidx.get(e.r32(ra + 0x30), -1), objidx.get(e.r32(rb + 0x30), -1)
        low = (0 <= ia <= 2) or (0 <= ib <= 2)      # pairs that touch the first three entries answer true sometimes
        yes = low and picks[i % len(picks)] < 0.2 and st["budget"] < 40
        if yes:
            st['budget'] += 1
            if picks[(i * 7) % len(picks)] < 0.7:
                e.w8(rb + 0x34, 1)                          # the answered j is flagged: it is skipped in the scans, and
                                                            # popped later as a pivot (its flag then matters in the swaps)
        e.ret(eax=1 if yes else 0, argbytes=8)

    only_hooks(c, {0x4ae5a0: pairtest})
    g = rnd(c, 0x1b00)
    e.wf32(g + 0x48, r.choice([0.016, 0.05, 0.5]))
    e.w32(0x70039c, g)

    n = r.randint(0, 50)
    table = rnd(c, 0x100 + 4 * n)
    e.w32(table + 4, n)
    for i in range(n):
        flagged = r.random() < 0.9
        sub = rnd(c, 0x80)
        e.w32(sub + 0x3c, (r.getrandbits(32) & ~0x1000) | (0x1000 if flagged else 0))
        obj = vt_object(c, 0x800, {0x438: ans(r.random() < 0.1), 0x2fc: ans(r.random() < 0.1), 0x57c: v57c},
                        nslots=0x180, name='ent')
        objidx[obj] = i
        e.w32(obj + 8, sub)
        e.w8(obj + 0x776, r.choice([0, 1, 1, 1]))
        e.wf32(obj + 0x624, r.uniform(-5.0, 40.0))
        e.w32(table + 8 + 4 * i, obj)
    e.w32(0x7003b8, table)
    return [rnd(c, 0x40)]


S(0x4aea10, 'Pass4aea10 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch852')
