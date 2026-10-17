"""specs_s1234.py - pathfinding batch 1234: ZActor::OnPathFound(request) (0x479910).

The request (0x20 bytes) carries a path list (+0x1c: count +8, 16-byte records at +0xc: f0 at +0, point at +4) or no list.
The actor's vtable slots, the engine (+0x9b message table, its +0xadc collision object, and the engine's own slot 0x1c4 that
returns a float in ST0), the path object at +0x73e, and the object the bounds come from (message table slot 0x58) are logged
stubs in both builds. Stub results are picked from the call-log position, so both builds get the same values for the same
call sequence. Float values pass through sf() (float32)."""
from pilot import S
from pfspec import rnd, reporter, vtable, sf, log_args


def _alloc(c, cap=0x200000):
    """g_pAllocator (0x70038c): slot +8 is alloc (fresh fake-heap memory), slot +0x10 is free (a logged no-op; the
    exe's array delete at 0x41e2c0 calls it)."""
    e = c.emu

    def new(em, rr):
        n = em.arg32(0)
        em.calllog.append(('alloc', n))
        em.ret(eax=em.alloc(n, 16, 0x5a) if n < cap else 0, argbytes=4)

    def free(em, rr):
        em.calllog.append(('free',))
        em.ret(argbytes=4)
    a = e.alloc(16)
    e.w32(a, e.fake_vtable('allocator', 0x8, {8: new, 0x10: free}))
    e.w32(0x70038c, a)


def _vt(c, name, n, table):
    """table: {byte_off: (stack words, fn(emu, raw_args) -> (eax, st0))}: a logged thiscall slot table."""
    slots = {}
    for off, (nw, fn) in table.items():
        def h(em, rr, off=off, nw=nw, fn=fn):
            raw = [em.arg32(k) for k in range(nw)]
            em.calllog.append((name, off, em.reg('ecx'), tuple(log_args(em, nw, {}))))
            eax, st0 = fn(em, raw)
            em.ret(eax=eax or 0, argbytes=4 * nw, st0=st0)
        slots[off] = h
    return c.emu.fake_vtable(name, n, slots)


def _opf(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    _alloc(c)
    # values the stubs hand out, indexed by call-log position (the same in both builds)
    vlist = [sf(c.fv(-300, 300)) for _ in range(64)]
    flist = [sf(c.fv(-40, 40)) for _ in range(64)]
    bits = [r.random() < 0.25 for _ in range(64)]
    ints = [r.getrandbits(31) | 1 for _ in range(64)]

    def pick(em, tab):
        return tab[len(em.calllog) % len(tab)]

    # the name the reporter prints for the actor (vtable +0x20 returns this object; +4 is the name, or 0)
    name = e.alloc(16)
    e.wbytes(name, b'ActorName\x00')
    nobj = e.alloc(16)
    e.w32(nobj + 4, name if r.random() < 0.7 else 0)

    def zero(em, a):
        return 0, None

    def getv(em, a):
        return nobj, None

    def move_out(em, a):
        # 0x4c: the vector out pointer gets three values
        for k in range(3):
            em.wf32(a[0] + 4 * k, pick(em, vlist) if k == 0 else pick(em, vlist[::-1]) if k == 1 else pick(em, flist))
        return 0, None

    def tmp_end(em, a):
        # 0x5c: the vector out pointer gets three values; its first dword is zero on every third call, so the walk ends
        n5 = sum(1 for t in em.calllog if t[0] == 'path' and t[1] == 0x5c)
        for k in range(3):
            em.wf32(a[0] + 4 * k, pick(em, flist) if k != 2 else pick(em, vlist))
        if n5 % 3 == 0:
            em.w32(a[0], 0)
        return pick(em, ints), None

    def obj_xform(em, a):
        # 0x8c: the object transforms the point in place (a fixed affine map, rounded to float32)
        for k in range(3):
            v = em.rf32(a[0] + 4 * k)
            em.wf32(a[0] + 4 * k, sf(sf(v) * 0.75 + sf(flist[k * 7 % 64]) * 0.125))
        return 0, None

    def obj_bool(em, a):
        return (1 if pick(em, bits) else 0), None

    def st0_float(em, a):
        return 0, pick(em, vlist)

    def coll_query(em, a):
        return pick(em, ints), None

    # path object (+0x73e): its vtable carries the 0x4c / 0x5c point walk, 0xc, and the +4 call
    x = e.alloc(0x40)
    e.w32(x, _vt(c, 'path', 0x40, {0x4c: (1, move_out), 0x5c: (1, tmp_end), 0xc: (0, zero), 0x4: (1, zero)}))

    # the message table: slot 0x58 gives the object the bounds come from; +0xadc is the collision object
    coll = e.alloc(0x40)
    e.w32(coll, _vt(c, 'collision', 0x90, {0x218: (3, coll_query), 0x220: (1, zero)}))
    msg = e.alloc(0xb00)
    bounds = e.alloc(0x60)
    for k, off in enumerate((0x40, 0x44, 0x48)):
        e.wf32(bounds + off, sf(c.fv(-120, 300)))
    obj = e.alloc(0x20)
    e.w32(obj, _vt(c, 'bounds', 0x80, {0x8c: (1, obj_xform), 0x180: (2, obj_bool), 0x84: (1, zero)}))
    e.w32(obj + 8, bounds)
    e.w32(msg, _vt(c, 'msgtable', 0x60, {0x58: (1, lambda em, a: (obj, None))}))
    e.w32(msg + 0xadc, coll)

    # the engine object (0x70039c): slot 0x1c4 (two args) returns the float 0x4e0a10 reads
    sysi = rnd(c, 0xa0)
    e.w32(sysi, _vt(c, 'engine', 0x80, {0x1c4: (2, st0_float)}))
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)

    # the actor
    actor = rnd(c, 0x1000)
    actor_vt = _vt(c, 'actor', 0x300, {
        0x20: (0, getv), 0x220: (1, zero), 0x628: (3, zero), 0x64c: (1, zero),
        0x5f4: (0, zero), 0x5f8: (0, zero), 0x650: (0, zero)})
    e.w32(actor, actor_vt)
    e.w32(actor + 0x73e, x)
    e.w32(actor + 0x691, r.choice([1, 1, 1, 0]))
    for off in (0x6c3, 0x6c4, 0x6c5, 0x699, 0x6fe, 0x726, 0x72f):
        e.w8(actor + off, r.choice([0, 1]))
    e.wf32(actor + 0x6b2, sf(r.choice([0.0, c.fv(0, 60)])))
    e.wf32(actor + 0x6b6, sf(r.choice([0.0, c.fv(-5, 60)])))
    e.wf32(actor + 0x6ba, sf(c.fv(-50, 50)))
    e.w32(actor + 0x6bf, 0x20000000 | r.getrandbits(20) if r.random() < 0.8 else 0)
    e.w32(actor + 0x64c, r.choice([0, 1, 0xb, 3]))
    e.w32(actor + 0x678, r.getrandbits(32))
    e.w32(actor + 0x722, r.getrandbits(32))
    e.w32(actor + 0x732, r.getrandbits(32))
    e.wf32(0x6ffa48, sf(r.choice([0.0, c.fv(-2, 2)])))

    # the path list the request carries (or none)
    rec = e.alloc(0x20)
    e.w32(rec + 0x18, 1)
    if r.random() < 0.85:
        n = r.randint(1, 4)
        lst = e.alloc(0x18)
        arr = e.alloc(16 * (n + 2))
        f0 = sorted(sf(c.fv(0, 400)) for _ in range(n))
        for k in range(n):
            e.wf32(arr + 16 * k, f0[k])
            for j in range(3):
                e.wf32(arr + 16 * k + 4 + 4 * j, sf(c.fv(-300, 300)))
        e.wf32(lst + 4, sf(c.fv(0, 400)))
        e.w32(lst + 8, n)
        e.w32(lst + 0xc, arr)
        e.w32(lst + 0x10, e.alloc(4) if r.random() < 0.5 else 0)
        e.w32(lst + 0x14, e.alloc(4) if r.random() < 0.5 else 0)
        e.w32(rec + 0x1c, lst)
    else:
        e.w32(rec + 0x1c, 0)
    e.w32(actor + 0x695, e.alloc(0x18) if r.random() < 0.5 else 0)
    return [actor, rec]


S(0x479910, 'ZActor::OnPathFound', 'thiscall', None, gen=_opf, n=1000)
