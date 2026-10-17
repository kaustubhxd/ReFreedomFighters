"""specs_s240017.py - Sonnet-w4a: 0x634879 crash report."""
import pe_emu
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _cell(c, cell, handler):
    e = c.emu
    a = e.r32(cell)
    e.stubs[a] = (e.stubs[a][0], handler)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x725808, _w(c))
    hook_rec(c, 0x663bc2, 1, pop=4, ret=lambda em, k: 0)   # feature check: the non-zero path is the int 0x29 trap (not exercised)
    hook_rec(c, 0x634d10, 3, pop=0, stackmark=(0,), ret=lambda em, k: _w(c))
    dbg = r.choice([0, 1, 1])
    _cell(c, 0x67606c, lambda em, res: (em.calllog.append(('dbg',)), em.ret(eax=dbg, argbytes=0)))
    _cell(c, 0x676160, lambda em, res: (em.calllog.append(('setuef', em.arg32(0))), em.ret(eax=_w(c), argbytes=4)))
    res_uef = r.choice([0, 0, 1, 0xffffffff])

    def uef(em, res):
        p = em.arg32(0)
        rec, ctx = em.r32(p), em.r32(p + 4)
        em.calllog.append(('uef', bytes(em.rbytes(rec, 0x50)).hex(), bytes(em.rbytes(ctx, 0x2cc)).hex()))
        em.ret(eax=res_uef, argbytes=4)
    _cell(c, 0x676168, uef)
    return [_w(c), _w(c), _w(c), _w(c), _w(c)]


S(0x634879, 'GUESS crash report', ('regs', ['ecx', 'edx', 'ebx', 'edi', 's']), None, ret='eax', gen=_gen, note='batch240017')
