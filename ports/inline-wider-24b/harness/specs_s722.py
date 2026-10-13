"""specs_s722.py - soldier AI batch 722: CFFCoverList::Init. The world: the engine global record at 0x7003b8 (heap object),
the db (0x4c geom->ref, 0x9b, 0xadc scene), the scene chain (head at +8, next via slot 0x50 in place), objects with an info
record at +0x54 (name at +4) and a vtable (0x80 root TM, 0x210 flag), the owner geom at +0x44. Names are random among
"coverboxl", "coverboxm", "coverboxh", "coverarrowl", "coverarrowm", "coverarrowh", "coverspline", "coverbox",
"coverarrow", "nothing" and NONAME. The builders (5868e0, 585ed0, 586760, 585a40) are hooked (logged); alloc (6014a0),
release (54f870), new (41e290) and delete (634273) are hooked; striwcmp runs as exe code with a strchr stub (cdecl)."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s709 import _log_world
from specs_s705 import nostk


def _ini(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, 0, args))

    # strchr (cdecl import used by striwcmp): pops nothing
    def strchr(em, r):
        sp, ch = em.arg32(0), em.arg32(1) & 0xff
        i = 0
        while True:
            b = em.mu.mem_read(sp + i, 1)[0]
            if b == ch:
                em.ret(eax=sp + i, argbytes=0)
                return
            if b == 0:
                em.ret(eax=0, argbytes=0)
                return
            i += 1
    e.stub_import('strchr', strchr)

    # _memicmp (cdecl import used by striwcmp): case-insensitive compare of count bytes, pops nothing
    def memicmp(em, r):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        res = 0
        for i in range(n):
            x = em.mu.mem_read(a + i, 1)[0]
            y = em.mu.mem_read(b + i, 1)[0]
            x = x + 32 if 65 <= x <= 90 else x
            y = y + 32 if 65 <= y <= 90 else y
            if x != y:
                res = x - y
                break
        em.ret(eax=res & 0xffffffff, argbytes=0)
    e.stub_import('_memicmp', memicmp)

    def stricmp(em, r):
        a, b = em.arg32(0), em.arg32(1)
        i = 0
        res = 0
        while True:
            x = em.mu.mem_read(a + i, 1)[0]
            y = em.mu.mem_read(b + i, 1)[0]
            xl = x + 32 if 65 <= x <= 90 else x
            yl = y + 32 if 65 <= y <= 90 else y
            if xl != yl:
                res = xl - yl
                break
            if x == 0:
                break
            i += 1
        em.ret(eax=res & 0xffffffff, argbytes=0)
    e.stub_import('_stricmp', stricmp)

    # allocation and release
    e.hook(0x6014a0, lambda em, r: (log('alloc', 0, (em.arg32(0),)), em.ret(eax=_rnd(c, max(em.arg32(0), 16)), argbytes=4)))
    e.hook(0x54f870, lambda em, r: (log('free', 0, (em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=8)))
    e.hook(0x41e290, lambda em, r: (log('new', 0, (em.arg32(0),)), em.ret(eax=_rnd(c, max(em.arg32(0), 16)), argbytes=0)))
    e.hook(0x634273, lambda em, r: (log('delete', 0, (em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=0)))

    # the builders, logged
    def builder(name, nargs, argb, adds=False):
        def h(em, r):
            log(name, 0, tuple(nostk(em.arg32(k)) for k in range(nargs)))
            if not adds:
                em.ret(eax=0, argbytes=argb)
                return
            # a built spot: append one random record to the spot vector at self+0x6b (when there is room)
            self_ = em.reg('ecx')
            vec = em.r32(self_ + 0x6b)
            if vec:
                end, cap = em.r32(vec + 4), em.r32(vec + 8)
                if end and end != cap:
                    em.wbytes(end, c.rng.randbytes(0x48))
                    em.w32(vec + 4, end + 0x48)
            em.ret(eax=0, argbytes=argb)
        return h
    e.hook(0x5868e0, builder('AroundBox', 3, 12, adds=True))
    e.hook(0x585ed0, builder('ForArrow', 3, 12, adds=True))
    e.hook(0x586760, builder('AlongSpline', 3, 12, adds=True))
    e.hook(0x585a40, builder('CreateSpot', 7, 0x1c, adds=True))

    # own logger: printf records all its arguments (the totals line has three)
    logobj2 = _rnd(c, 16)

    def printf2(em, r):
        fmt = em.arg32(1)
        raw = em.rbytes(fmt, 200)
        raw = raw[:raw.index(0)] if 0 in raw else raw
        nspec = sum(1 for i in range(len(raw) - 1) if raw[i] == 0x25 and raw[i + 1] in b'ds')   # '%d' / '%s'
        args = tuple(nostk(em.arg32(k)) for k in range(1, 2 + nspec))   # only the arguments the format consumes
        em.calllog.append(('log.printf', 0x2c, None, args))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj2, e.fake_vtable('log2', 16, {0x2c: printf2}))
    lg2 = _rnd(c, 16)
    e.w32(lg2, e.logging_vtable('logger2', 16, impl={0x20: lambda em, a: (logobj2, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg2)

    # global record
    gl = _rnd(c, 0x3000)
    e.w32(0x7003b8, gl)

    # engine, db, scene
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0xb00)
    e.w32(eng + 0x9b, db)
    e.w32(db + 0x9b - 0x9b, 0)   # keep the layout explicit (no-op)

    def db4c(em, r):
        log('db', 0x4c, (em.arg32(0),))
        em.ret(eax=c.rng.getrandbits(32), argbytes=4)
    e.w32(db, e.fake_vtable('db', 0x60, {0x4c: db4c}))

    names_pool = [e.cstr(n) for n in ('coverboxl', 'coverboxm', 'coverboxh', 'coverarrowl', 'coverarrowm',
                                      'coverarrowh', 'coverspline', 'coverbox', 'coverarrow', 'nothing')]
    count = c.rng.choice([0x800, 0x801]) if c.rng.random() < 0.01 else c.rng.choice([0, 1, 2, 3, 5, 8])   # big cases name every object 'coverboxl'
    objs = []
    geoms = []
    def rtm(em, r):
        m, p = em.arg32(0), em.arg32(1)
        log('object', 0x80, ())
        em.wbytes(m, struct.pack('<12f', *[float(c.rng.uniform(-1, 1)) for _ in range(12)]))
        em.wbytes(p, struct.pack('<3f', *[float(c.rng.uniform(-200, 200)) for _ in range(3)]))
        em.ret(eax=0, argbytes=8)

    def flag(em, r):
        log('object', 0x210, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)
    geom_vt = e.fake_vtable('geom', 0x220, {0x80: rtm, 0x210: flag})   # one vtable for all geoms
    for _ in range(count):
        o = _rnd(c, 0x80)            # scene object: +0x54 is the geom (whose +4 is the name)
        g = _rnd(c, 0x80)
        pick = c.rng.random()
        e.w32(g + 4, names_pool[0] if count > 100 else (0 if pick < 0.1 else c.rng.choice(names_pool)))
        e.w32(o + 0x54, g)
        e.w32(g, geom_vt)
        objs.append(o)
        geoms.append(g)

    scene = _rnd(c, 0x40)
    cur_index = {'i': 0}
    def nxt(em, r):
        ptr = em.arg32(0)              # pointer to the current object (in place)
        cur = em.r32(ptr)
        i = cur_index['i']
        # the chain: head = objs[0], then objs[1] ... (scene+8 gives the head object pointer)
        if cur in objs:
            idx = objs.index(cur) + 1
        else:
            idx = 0
        em.w32(ptr, objs[idx] if idx < len(objs) else 0)
        em.ret(eax=0, argbytes=4)
    e.w32(scene, e.fake_vtable('scene', 0x60, {0x50: nxt}))
    e.w32(scene + 8, objs[0] if objs else 0)
    e.w32(db + 0xadc, scene)

    # self (the cover list): owner geom at +0x44, inline list at +0x5f empty, +0x6b null
    owner = _rnd(c, 0x40)
    cl = _rnd(c, 0x100)
    e.w32(cl + 0x44, owner)
    e.w32(cl + 0x5f, 0)
    e.w32(cl + 0x63, 0)
    e.w32(cl + 0x67, 0)
    e.w32(cl + 0x6b, 0)
    e.w8(cl + 0x56, 0)
    return [cl]


S(0x587a30, 'CFFCoverList::Init', 'thiscall', None, ret=None, gen=_ini,
  note='b722 [high]; builders hooked; alloc/free/new/delete hooked; striwcmp exe with strchr stub')
