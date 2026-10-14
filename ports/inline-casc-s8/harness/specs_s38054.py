"""specs_s38054.py - cascade s8 batch 38054. The config object at engine +0x1a9f (unaligned, null 15%) has a custom slot 0x60 stub that logs (section, name pointer) and returns a distinct value derived
from the name pointer (so a swapped name / destination is visible); this slot 0x578 returns a random section id; the memset (0x634d10) is a real-effect hook, so the cleared region and the unaligned dword
stores both land in the heap compare."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g592580(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def s60(em, res_):
        sec, name = em.arg32(0), em.arg32(1)
        em.calllog.append(('s60', em.reg('ecx'), sec, name))
        em.ret(eax=(name * 2654435761 + sec) & 0xffffffff, argbytes=8)
    cfg = obj(c, 0x40, {0x60: e.stub_fn('s60', s60)})
    so = sysobj(c, {})
    e.wbytes(so + 0x1a9f, struct.pack('<I', 0 if r.random() < 0.15 else cfg))

    def memset(em, res_):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memset', p, v, n))
        em.wbytes(p, bytes([v & 0xff]) * n)
        em.ret(eax=p, argbytes=0)
    e.hook(0x634d10, memset)
    me = obj(c, 0x1000, {0x578: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))})
    return [me]


S(0x592580, 'GUESS resolve config entries by name', 'thiscall', None, ret=None, gen=_g592580, note='batch38054')
