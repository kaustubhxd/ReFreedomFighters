"""specs_s38062.py - cascade s8 batch 38062. This object has custom logging slots 0x21c / 0x35c (1 arg) returning a value derived from the name pointer (so a wrong name or a wrong destination offset shows
in the heap compare and in the ordered call log); 0x481530 is a recording hook; the object is 0x800 random bytes (unaligned destinations included)."""
from pilot import S
from recruits_util import obj, clear_hooks, hook_rec


def _g58be30(c):
    clear_hooks(c)
    e = c.emu

    def mk(name, mul):
        def h(em, res_):
            a = em.arg32(0)
            em.calllog.append((name, em.reg('ecx') != 0, a))
            em.ret(eax=(a * mul + 0x1234567) & 0xffffffff, argbytes=4)
        return e.stub_fn(name, h)
    me = obj(c, 0x800, {0x21c: mk('s21c', 2654435761), 0x35c: mk('s35c', 40503)})
    hook_rec(c, 0x481530, 0, this=True)
    return [me]


S(0x58be30, 'GUESS resolve named ids of page', 'thiscall', None, ret=None, gen=_g58be30, note='batch38062')
