"""specs_s1691.py - residue 13 batch 1691: 0x461570. The allocator 0x41e290 (cdecl, one argument, recorded) returns a block;
the linksort constructor 0x4ccad0 (thiscall, two arguments, ret 8, recorded) returns a valid object; the object's slot 0x98
(three arguments, recorded) returns a block r with room for r[-4]. this+0x6c is zero (new path) or a valid object."""
from pilot import S, F
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED


def _alloc_ret(c, addr, ret):
    rec = c.emu.alloc(8, 4)

    def h(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.ret(eax=ret, argbytes=0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    blk = rnd(c, 0x40)
    _alloc_ret(c, 0x41e290, blk)
    valid = obj(c, 0x40, {0x98: stub(c, seq, 3, ret=blk + 8)})
    hook(c, seq, 0x4ccad0, 2, ret=valid, this=True, pop=True)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x6c, valid if r.random() < 0.5 else 0)
    return [me, F(r.uniform(-100, 100)), r.getrandbits(32), r.getrandbits(32)]


S(0x461570, 'GUESS FUN_461570', 'thiscall', None, ret='eax', gen=_gen, note='batch1691; linksort ctor hooked; slot 0x98 recorder')
