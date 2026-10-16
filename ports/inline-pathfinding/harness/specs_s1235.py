"""specs_s1235.py - pathfinding batch 1235: CPathUserProfile::GetUser (0x4875d0), CDoorBlocker::isOpen (0x4875e0),
CDoorBlocker::Activate (0x487490), CPathUserProfile::CanOpenDoor (0x487550), CPathUserProfile::CanPassPerson (0x560360).
The profile's slots (0 = CanOpenDoor, 8 = the user object), the user object's slot 0x130, the geometry's slot 0x128, and
the message table's slots 0x4c and 0x114 are logged stubs; each returns a value chosen from the call-log position, so both
builds get the same answers for the same call sequence."""
from pilot import S
from pfspec import rnd, vtable, sf, log_args, allocator


def _vt(c, name, n, table):
    slots = {}
    for off, (nw, fn) in table.items():
        def h(em, rr, off=off, nw=nw, fn=fn):
            raw = [em.arg32(k) for k in range(nw)]
            em.calllog.append((name, off, em.reg('ecx'), tuple(log_args(em, nw, {}))))
            eax = fn(em, raw)
            em.ret(eax=eax or 0, argbytes=4 * nw)
        slots[off] = h
    return c.emu.fake_vtable(name, n, slots)


def _pick(em, tab):
    return tab[len(em.calllog) % len(tab)]


def _gen_common(c, flags_probs=(0.5, 0.5)):
    r = c.rng
    e = c.emu
    vals = [r.getrandbits(32) for _ in range(64)]
    bools = [r.random() < 0.5 for _ in range(64)]
    words = [r.getrandbits(16) for _ in range(64)]
    user = e.alloc(0x20)
    e.w32(user, _vt(c, 'user', 0x60, {0x130: (2, lambda em, a: 0)}))
    prof = rnd(c, 0x40)
    e.w8(prof + 0xa, r.choice([0, 1]))
    e.w8(prof + 0xb, r.choice([0, 1]))
    e.w16(prof + 4, r.getrandbits(16))
    e.w32(prof + 6, r.getrandbits(32))
    e.w32(prof, _vt(c, 'profile', 0x20, {
        0: (1, lambda em, a: 1 if _pick(em, bools) else 0),
        8: (0, lambda em, a: user),
    }))
    msg = e.alloc(0xb00)
    e.w32(msg, _vt(c, 'msgtable', 0x60, {
        0x4c: (1, lambda em, a: _pick(em, vals)),
        0x114: (5, lambda em, a: _pick(em, words)),
    }))
    sysi = rnd(c, 0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    return user, prof, msg, vals, bools, words


def _gen_geom(c):
    r = c.rng
    e = c.emu
    user, prof, msg, vals, bools, words = _gen_common(c)
    geom = e.alloc(0x20)
    vals2 = [r.getrandbits(32) for _ in range(64)]

    def geom_fn(em, a):
        # 0x128: the value at the second pointer may be written (the exe's CanOpenDoor reads it back)
        if _pick(em, bools):
            em.w32(a[1], _pick(em, vals2))
        return 0
    e.w32(geom, _vt(c, 'geom', 0x60, {0x128: (3, geom_fn)}))
    return [prof, geom]


def _gen_door(c):
    r = c.rng
    e = c.emu
    user, prof, msg, vals, bools, words = _gen_common(c)
    door = e.alloc(0x20)
    e.w32(door + 4, r.getrandbits(32))
    return [door, prof]


def _gen_isopen(c):
    # the same as _gen_door, but a third of the cases pass no profile (the door is open then)
    args = _gen_door(c)
    if c.rng.random() < 0.33:
        args[1] = 0
    return args


def _gen_obj(c):
    r = c.rng
    e = c.emu
    user, prof, msg, vals, bools, words = _gen_common(c)
    return [prof, e.alloc(0x10)]


def _gen_user(c):
    r = c.rng
    e = c.emu
    user, prof, msg, vals, bools, words = _gen_common(c)
    return [prof]


S(0x4875d0, 'CPathUserProfile::GetUser', 'thiscall', None, gen=_gen_user, n=300)
S(0x4875e0, 'CDoorBlocker::isOpen', 'thiscall', None, ret='al', gen=_gen_isopen, n=300)
S(0x487490, 'CDoorBlocker::Activate', 'thiscall', None, gen=_gen_door, n=300)
S(0x487550, 'CPathUserProfile::CanOpenDoor', 'thiscall', None, ret='al', gen=_gen_geom, n=300)
S(0x560360, 'CPathUserProfile::CanPassPerson', 'thiscall', None, ret='al', gen=_gen_obj, n=300)
