"""specs_s1507.py - recruits thread batch 1507: CharismaAddExperience, FindNextRecruit, is-my-recruit, is-selected,
OSD sound with volume, name-ref resolve.
Recorders: OSD sounds, MessageAdd, GUI sound, CharismaSet, IsRecruited, the helper calls under FindNextRecruit,
the text table (returns a test string), the sprintf object (records format and amount, writes a short string into
the caller's buffer), the area search (a scripted list of actors). vdist2 runs as exe code."""
from pilot import S, F
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj, logger


def _is_mine(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x597a70, 1, ret=r.choice([0, 1, 0x100]), this=True)
    so = sysobj(c)
    c.emu.w32(so + 0x1b5d, r.choice([0, 1, 2]))
    s = rnd(c, 0x2400)
    n = r.choice([0, r.randint(1, 8), -1])
    c.emu.w32(s + 0x1fae, n & 0xffffffff)
    for i in range(max(n, 0)):
        c.emu.w32(s + 0x1dae + 4 * i, r.randint(1, 9))
    return [s, r.randint(1, 10)]


def _is_sel(c):
    clear_hooks(c)
    r = c.rng
    s = rnd(c, 0x400)
    n = r.choice([0, r.randint(1, 8), -1])
    c.emu.w32(s + 0x2e6, n & 0xffffffff)
    for i in range(max(n, 0)):
        c.emu.w32(s + 0xe6 + 4 * i, r.randint(1, 9))
    return [s, r.randint(1, 10)]


def _snd_v(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x59a5e0, 1, ret=r.getrandbits(32), this=True)
    so_obj = rnd(c, 0x80)
    sysobj(c, table_slots={0x60: pystub(c, 1, ret=0 if r.random() < 0.3 else so_obj)})
    return [rnd(c, 0x100), r.randint(0, 8), F(r.choice([0.0, 1000.0, 2000.0, r.uniform(-5000, 5000)]))]


def _name_ref(c):
    clear_hooks(c)
    r = c.rng
    idv = r.getrandbits(32)

    def put(e, k):
        if r.random() < 0.8:
            e.w32(e.arg32(1), idv)
    names = obj(c, 0x20, {0x88: pystub(c, 2, nullflag=(1,), side=put)})
    ref = rnd(c, 8)
    c.emu.w32(ref, names)
    return [ref]


TEXTS = [b'+%d Charisma', b'%d', b'Charisma Point: %d!!', b'x' * 31, b'y' * 32, b'']


def _charisma(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    snd = r.getrandbits(32)
    hook_rec(c, 0x59a650, 2, ret=snd, this=True)
    hook_rec(c, 0x48aad0, 0, ret=r.getrandbits(32), this='mark')
    hook_rec(c, 0x59a580, 3, this=True, deref={0: -5})
    hook_rec(c, 0x4f9680, 1, this=True)
    hook_rec(c, 0x5a5e90, 1, this=True)
    txt = r.choice(TEXTS)
    tp = e.alloc(len(txt) + 4, 4)
    e.wbytes(tp, txt + b'\0')
    texts = obj(c, 0x20, {0: pystub(c, 2, ret=tp, this=True)})
    out = b'+%02d!' % r.randint(0, 99)   # fixed length: the record reads exactly the string and its NUL

    def spr(em, k):
        em.wbytes(em.arg32(1), out + b'\0')
    fmt = obj(c, 0x20, {0x198: pystub(c, 4, pop=0, stackmark=(1,), side=spr)})
    sndobj = rnd(c, 0x80)
    evo = obj(c, 0x20, {0x12c: pystub(c, 3)})
    so = sysobj(c, slots={0x190: pystub(c, 0, ret=fmt)},
                table_slots={0x138: pystub(c, 0, ret=rnd(c, 0x10)), 0x114: pystub(c, 4, ret=r.getrandbits(32)),
                             0x60: pystub(c, 1, ret=0 if r.random() < 0.3 else sndobj)}, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, evo)
    e.w32(tab + 0xae4, texts)
    s = rnd(c, 0x2400)
    e.w32(s + 0x1fb6, r.choice([0, 50, 90, 99, r.randint(0, 250), r.randint(-50, 0)]) & 0xffffffff)
    mx = r.randint(0, 12)
    e.w32(s + 0x1fbe, mx)
    e.w32(s + 0x1fba, r.choice([mx, max(mx - 1, 0), mx + 1]))
    e.w32(s + 0x22c2, r.randint(0, 5))
    e.w32(s + 0x1d0f, 0 if r.random() < 0.3 else rnd(c, 0x10))
    pos = rnd(c, 12)
    kind = r.choice(list(range(12)) + [0x80000000])
    show = r.getrandbits(32)
    if r.random() < 0.4:
        show &= 0xffffff00
    amount = r.choice([-1, -1, -1, r.randint(-50, 150)])
    return [s, kind, pos, show, amount & 0xffffffff]


def _find_next(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x2400)
    hp = [r.uniform(-500, 500) for _ in range(3)]

    def put3(vals):
        def f(em, k):
            p = em.arg32(0)
            for i, v in enumerate(vals):
                em.wf32(p + 4 * i, v)
        return f
    team = rnd(c, 0x20)
    hero = obj(c, 0x60, {0x84: pystub(c, 1, nullflag=(0,), side=put3(hp))})
    e.w32(hero + 0x54, team)
    e.w32(s + 0x1d0b, hero)
    actors = []
    ids = {}
    for i in range(r.randint(0, 6)):
        if r.random() < 0.1:
            actors.append(hero)
            continue
        ap = [hp[j] + r.uniform(-2000, 2000) for j in range(3)] if r.random() < 0.7 else [hp[j] for j in range(3)]
        a = obj(c, 0x800, {0x438: pystub(c, 0, ret=r.choice([0, 0, 0, 1, 0x100])),
                           0x84: pystub(c, 1, nullflag=(0,), side=put3(ap))})
        st = rnd(c, 0x10)
        e.w32(st + 8, 4 if r.random() < 0.1 else r.randint(0, 3))
        e.w32(a + 0x54, st)
        e.w32(a + 0x77f, 5 if r.random() < 0.1 else r.randint(0, 4))
        ids[a] = r.randint(1, 30)
        actors.append(a)
    nonrec = [r.randint(1, 30) for _ in range(r.randint(0, 4))]
    for i, v in enumerate(nonrec):
        e.w32(s + 0x2ef + 4 * i, v)
    e.w32(s + 0x4ef, len(nonrec))
    hook_rec(c, 0x597a20, 1, ret=lambda em, k: r.choice([0, 0, 0, 1, 0x100]), this=True)
    hook_rec(c, 0x597b10, 1, ret=lambda em, k: r.choice([0, 0, 0, 1]), this=True)

    def find(em, rr):
        cur = em.arg32(2)
        i = (em.r32(cur) + 1) & 0xffffffff
        em.w32(cur, i)
        em.ret(actors[i] if i < len(actors) else 0, 16)
    srch = 0 if r.random() < 0.05 else obj(c, 0x20, {0x84: e.stub_fn('area search', find)})
    e.w32(s + 0x4f7, srch)
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=lambda em, k: ids.get(em.arg32(0), 0))})
    return [s, 0 if r.random() < 0.3 else rnd(c, 8)]


S(0x597a20, 'ZGameOSD is my recruit (0x597a20)', 'thiscall', ret='al', gen=_is_mine, note='batch1507')
S(0x597b10, 'ZGameOSD is selected (0x597b10)', 'thiscall', ret='al', gen=_is_sel, note='batch1507')
S(0x59a650, 'ZGameOSD play sound with volume (0x59a650)', 'thiscall', ret='eax', gen=_snd_v, note='batch1507')
S(0x48aad0, 'name ref resolve (0x48aad0)', 'thiscall', ret='eax', gen=_name_ref, note='batch1507')
S(0x596940, 'ZGameOSD::CharismaAddExperience', 'thiscall', gen=_charisma, note='batch1507')
S(0x597720, 'ZGameOSD::FindNextRecruit', 'thiscall', ret='eax', gen=_find_next, note='batch1507')
