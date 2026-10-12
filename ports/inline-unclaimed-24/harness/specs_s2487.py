"""specs_s2487.py - decomp area 24, batch 2487.
0x53e940 CRigidBody::End(): operator delete (0x41e2c0, cdecl, recorded) on the pointer at +0x135 when set, then the dword is cleared.
0x478a80 ZActor::SMoveType::GetAnimHeader() const: zero for a zero first dword, else the system table object's dword at +0x44 plus it.
0x59ff70 ZFFActor::GetProjectilesInMagazine(int): table slot 0x58 with the dword at +0x78e (argument nonzero) or +0x78a; a non-null
result answers slot 0x35c, otherwise -1.
0x5a2d60 ZFFActor::SetHero(unsigned int): calls ZActor::SetHero (real code), then stores the table's slot 0x58 result at +0x92e."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks, hook_rec


def _end(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x41e2c0, 1, pop=0)
    o = rnd(c, 0x200)
    e.w32(o + 0x135, r.choice([0, rnd(c, 0x20)]))
    return [o]


def _anim(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    tbl = e.r32(so + 0x9b)
    e.w32(tbl + 0x44, r.getrandbits(32))
    o = rnd(c, 0x10)
    e.w32(o, r.choice([0, r.getrandbits(16)]))
    return [o]


def _proj(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rv = r.getrandbits(32)
    child = obj(c, 0x40, {0x35c: pystub(c, 0, ret=rv)})
    target = r.choice([0, child])
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=target)})
    o = rnd(c, 0x1000)
    e.w32(o + 0x78a, r.getrandbits(32))
    e.w32(o + 0x78e, r.getrandbits(32))
    return [o, r.choice([0, 1, 7])]


def _hero(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=0x77)})
    o = rnd(c, 0x1000)
    return [o, r.getrandbits(32)]


S(0x53e940, 'CRigidBody::End', 'thiscall', None, ret=None, gen=_end, note='batch2487')
S(0x478a80, 'ZActor::SMoveType::GetAnimHeader', 'thiscall', None, ret='eax', gen=_anim, note='batch2487')
S(0x59ff70, 'ZFFActor::GetProjectilesInMagazine', 'thiscall', None, ret='eax', gen=_proj, note='batch2487')
S(0x5a2d60, 'ZFFActor::SetHero', 'thiscall', None, ret=None, gen=_hero, note='batch2487')
