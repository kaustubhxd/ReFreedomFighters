"""specs_s33048.py - h3 () batch 33048."""
import pe_emu
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g640e80(c):
    clear_hooks(c)
    r = c.rng
    stub = pystub(c, 1, this=True)
    o = obj(c, 0x20, {4: stub})
    me = rnd(c, 0x1a0)
    c.emu.w32(me + 0x17f, r.choice([o, o, 0]))
    return [me]


def _g466480(c):
    clear_hooks(c)
    stub = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x40, {0x2a8: stub}), _w(c)]


def _g445dc0(c):
    clear_hooks(c)
    r = c.rng
    stub8c = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    rr = obj(c, 0x20, {0x8c: stub8c})
    stub100 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([rr, rr, 0]))
    return [obj(c, 0x40, {0x100: stub100})]


def _g472400(c):
    clear_hooks(c)
    e = c.emu
    stub = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    vt = e.alloc(0x20, 4)
    e.w32(vt + 8, stub)
    me = rnd(c, 0x300)
    e.w32(me + 0x2e7, vt)
    return [me, _w(c)]


def _g54a0c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x54d910, 0, this=True, ret=lambda em, k: _w(c))
    stub = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    o = obj(c, 0x40, {0x18: stub})
    me = rnd(c, 0x8100)
    c.emu.w32(me + 0x8061, r.choice([o, o, 0]))
    return [me]


def _g4634d0(c):
    clear_hooks(c)
    r = c.rng
    stub = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, _w(c)]))
    o = obj(c, 0x40, {0x14: stub})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, r.choice([o, o, 0]))
    return [me]


def _g4949a8(c):
    clear_hooks(c)
    e = c.emu
    stub = pystub(c, 4, pop=0, ret=lambda em, k: _w(c))
    g = obj(c, 0x40, {0x24: stub})
    e.w32(0x700390, g)
    ebp = pe_emu.STACK_TOP - 0x80
    e.w32(ebp - 0xa0, _w(c))
    e.w32(ebp - 0x9c, _w(c))
    return []


S(0x640e80, 'GUESS dtor-ish vtable + delete child', 'thiscall', None, ret=None, gen=_g640e80, note='batch33048')
S(0x466480, 'GUESS vcall 0x2a8(0,a)', 'thiscall', None, ret='eax', gen=_g466480, note='batch33048')
S(0x445dc0, 'GUESS lookup then vcall 0x8c', 'thiscall', None, ret='eax', gen=_g445dc0, note='batch33048')
S(0x472400, 'GUESS subobject vcall 8(this,a)', 'thiscall', None, ret='eax', gen=_g472400, note='batch33048')
S(0x54a0c0, 'GUESS vcall 0x18 then tail 54d910', 'thiscall', None, ret='eax', gen=_g54a0c0, note='batch33048')
S(0x4634d0, 'GUESS child vcall 0x14 bool', 'thiscall', None, ret='al', gen=_g4634d0, note='batch33048')
S(0x4949a8, 'GUESS SEH funclet log call', 'cdecl', None, ret='eax', gen=_g4949a8, note='batch33048')


def _g4233db(c):
    clear_hooks(c)
    e = c.emu
    stub = pystub(c, 4, pop=0, ret=lambda em, k: _w(c))
    g = obj(c, 0x40, {0x24: stub})
    e.w32(0x700390, g)
    ebp = pe_emu.STACK_TOP - 0x80
    # the 0xcc fill of the stack below esp makes [ebp-0x4c0] read as 0xcccccccc: back that address with real memory
    try:
        e.mu.mem_map(0xcccc0000, 0x10000)
    except Exception:
        pass
    e.w32(0xcccccccc, _w(c))
    e.wbytes(0xccccccd0, bytes(4))
    e.w32(0xccccccd0, _w(c))
    e.w32(0xccccccd0 - 0xc, _w(c))
    return []


S(0x4233db, 'GUESS SEH funclet log call 2', 'cdecl', None, ret='eax', gen=_g4233db, note='batch33048')
