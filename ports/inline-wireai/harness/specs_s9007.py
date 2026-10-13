"""specs_s9007.py - wire-ai batch 9007: PlayBodySound 0x546980. Engine [0x70039c] with the sound system +0x1a9f (null 5 %; slots 0x58
sound(category, set), 0x5c category / set by name, 0x60 sound(set, name)), the geom database +0x9b (0x138 the name table whose 0x88(name,
&ref) gives the hero's ref, 0x58 ref -> geom, 0x54 id -> geom, 0x60 handle -> sound object, 0x160 material -> object), the render system
+0x1aa3 -> +0x18 (slot 0xf8 material record), the clock +0x40 and the random slot 0x1c0 (ST0). The statics 0x711cf8 / 0x711d1c start random
(0, around the clock, far before / after). ZBaseGeom::GetOwnerRoom 0x4db3b0 and ZGROUP::AddSound3d 0x43ec00 are hooked recorders; mreset runs
as exe code. Every lookup may fail (returns 0) so each branch is taken."""
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import nostk


def _pbs(c):
    e, r = c.emu, c.rng
    log = lambda name, off, args: e.calllog.append((name, off, None, tuple(nostk(a) for a in args)))
    def ret_from(name, off, nargs, gen):
        def h(em, rr):
            log(name, off, tuple(em.arg32(k) for k in range(nargs)))
            em.ret(eax=gen(), argbytes=4 * nargs)
        return h
    pick = lambda *vals: (lambda: r.choice(vals))
    eng = _rnd(c, 0x1c00)
    now = r.randint(0x1000, 1 << 24)
    e.w32(eng + 0x40, now)

    def draw(em, rr):
        log('rand', 0x1c0, (em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8, st0=r.choice([0.0, 0.5, 0.75, 0.999, r.random(), r.random() * 1e-3, r.uniform(1e-7, 1e-5)]))
    e.w32(eng, e.fake_vtable('engine', 0x80, {0x1c0: draw}))
    e.w32(0x70039c, eng)
    snd = _rnd(c, 0x40)
    e.w32(snd, e.fake_vtable('sounds', 0x20, {
        0x58: ret_from('snd', 0x58, 2, pick(0, r.getrandbits(32) | 1, r.getrandbits(32) | 1)),
        0x5c: ret_from('snd', 0x5c, 1, pick(0, r.getrandbits(32) | 1)),
        0x60: ret_from('snd', 0x60, 2, pick(0, r.getrandbits(32) | 1))}))
    e.w32(eng + 0x1a9f, 0 if r.random() < 0.05 else snd)
    # hero
    hero = _rnd(c, 0x600)
    e.w32(hero + 0x417, (e.r32(hero + 0x417) & ~0x800) | (0x800 if r.random() < 0.6 else 0))
    e.w32(hero, e.fake_vtable('hero', 0x160, {0x578: ret_from('hero', 0x578, 0, pick(r.getrandbits(32)))}))
    nm = _rnd(c, 0x20)
    heroRef = r.getrandbits(32)

    def name_lookup(em, rr):
        log('names', 0x88, (em.arg32(0),))
        em.w32(em.arg32(1), heroRef)
        em.ret(eax=0, argbytes=8)
    e.w32(nm, e.fake_vtable('names', 0x24, {0x88: name_lookup}))
    geom = _rnd(c, 0x80)
    so = _rnd(c, 0x100)
    mo = _rnd(c, 0x40)

    def by_ref(em, rr):
        ref = em.arg32(0)
        log('db', 0x58, (ref,))
        em.ret(eax=(hero if (ref == heroRef and r.random() < 0.85) else 0), argbytes=4)
    db = _rnd(c, 0x20)
    e.w32(db, e.fake_vtable('db', 0x5a, {
        0x138: ret_from('db', 0x138, 0, lambda: nm),
        0x58: by_ref,
        0x54: ret_from('db', 0x54, 1, lambda: geom if r.random() < 0.9 else 0),
        0x60: ret_from('db', 0x60, 1, lambda: so if r.random() < 0.85 else 0),
        0x160: ret_from('db', 0x160, 1, lambda: mo if r.random() < 0.7 else 0)}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))
    rec = _rnd(c, 0x10)
    mat = _rnd(c, 0x20)
    e.w32(mat, e.fake_vtable('matsrc', 0x40, {0xf8: ret_from('matsrc', 0xf8, 1, lambda: rec if r.random() < 0.8 else 0)}))
    rs = _rnd(c, 0x40)
    e.w32(rs + 0x18, mat)
    e.wbytes(eng + 0x1aa3, struct.pack('<I', rs))
    room = _rnd(c, 0x20)
    e.hook(0x4db3b0, lambda em, rr: (log('GetOwnerRoom', 0, ()), em.ret(eax=room)))

    def add3d(em, rr):
        m, p = em.arg32(0), em.arg32(1)
        log('AddSound3d', 0, tuple(struct.unpack('<9I', em.rbytes(m, 36))) + tuple(struct.unpack('<3I', em.rbytes(p, 12))) + tuple(em.arg32(k) for k in range(2, 6)))
        em.ret(eax=r.choice([0, r.getrandbits(32) | 1, r.getrandbits(32) | 1]), argbytes=24)
    e.hook(0x43ec00, add3d)
    e.wbytes(0x711cf8, struct.pack('<f', f32(r.choice([0.5, 0.8, r.uniform(0, 2)]))))
    e.w32(0x711d1c, r.choice([0, 0, now, now - 400, now - 512, now - 513, now - 511, now - 819, now - 820, now - 600, now - 900, now + 5000, r.getrandbits(31)]) & 0xffffffff)
    pos = e.alloc(16, 4)
    e.wbytes(pos, struct.pack('<3f', *[f32(r.uniform(-1000, 1000)) for _ in range(3)]))
    return [pos, r.choice([0, 1, 0x100]), struct.unpack('<I', struct.pack('<f', f32(r.uniform(0, 1))))[0], r.getrandbits(32), r.choice([0, 1, 0x100])]


S(0x546980, 'PlayBodySound', 'fastcall', None, ret='eax', gen=_pbs, note='b9007; GetOwnerRoom / AddSound3d hooked, mreset as exe code')
