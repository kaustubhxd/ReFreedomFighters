"""specs_s1523.py - recruits thread batch 1523: CFormationControl::Load (0x5b6e20).
The reader (ZLoadGame stand-in) is a recorder: slot 0x18 (read ptr, size) fills the block with a deterministic
pattern; 4-byte reads return small values (0..2) so the counts and keys stay small. The formation table is a fake
whose slot 4 (get-or-create by key) returns a pool record at pool + 0x100*key + 4 (save-side address + 4, as the
original's record). operator new (0x41e290) returns pool blocks; REFTAB's constructor and InitWrapper (exe code, with
the name table and object manager set up as in batch 1513) run as original code."""
from pilot import S
from recruits_util import rnd, obj, hook_rec, clear_hooks, sysobj


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    # operator new: pool blocks of 0x1c bytes (never null here: REFTAB construction is covered by batch 1513)
    blocks = [rnd(c, 0x1c) for _ in range(8)]
    hook_rec(c, 0x41e290, 1, ret=lambda em, k: blocks[min(k, 7)], pop=0)
    pool = e.alloc(3 * 0x100 + 8, 16)
    cnt = e.alloc(4, 4)
    e.w32(cnt, 0)

    def read(em, rr):
        ptr, size = em.arg32(0), em.arg32(1)
        k = em.r32(cnt)
        em.w32(cnt, k + 1)
        if size == 4:
            em.w32(ptr, k % 3)
        else:
            em.wbytes(ptr, bytes(((k * 37 + i * 11) & 0xff) for i in range(size)))
        em.ret(0, 8)

    def slot4(em, rr):
        key = em.arg32(0)
        em.ret(pool + 0x100 * (key % 3) + 4, 4)
    lg = obj(c, 0x20, {0x18: e.stub_fn('load read', read)})
    fake_table = obj(c, 0x40, {4: e.stub_fn('table get-or-create', slot4)})
    this = rnd(c, 0x100)
    e.w32(this + 0x44, rnd(c, 0x20))
    e.w32(this + 0x48, fake_table)
    # InitWrapper (exe) needs: name table (0x138) with a 0x60 (register) and 0x4c (lookup), object manager 0x70038c
    names = obj(c, 0x80, {0x60: pystub_(c, 3)})
    sysobj(c, table_slots={0x138: e.stub_fn('names', lambda em, rr: em.ret(names, 0)),
                           0x4c: e.stub_fn('lookup', lambda em, rr: em.ret(0x55, 4))})
    om = obj(c, 0x20, {0x20: e.stub_fn('om', lambda em, rr: em.ret(0, 4)), 0xac: e.stub_fn('om reg', lambda em, rr: em.ret(0, 4))})
    e.w32(0x70038c, om)
    return [this, lg]


def pystub_(c, nargs):
    from recruits_util import pystub
    return pystub(c, nargs, this=True)


S(0x5b6e20, 'CFormationControl::Load', 'thiscall', ret='al', gen=_gen, note='batch1523', teb=True)
