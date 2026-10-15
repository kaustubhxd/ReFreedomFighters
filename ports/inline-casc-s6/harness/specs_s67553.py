"""specs_s67553.py - cascade s6 batch 67553 (0x4acb30, thiscall(stream) ret 4, returns al=1). The stream object's slots 0x3c / 0x40 / 0x6c are recorders (1 arg, call order logged; slot 0x40 logs every value in the call log since the stock recorder keeps only the last row); the object is a
random block, so the words and the dword written out are random and distinguish the offsets."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4acb30(c):
    clear_hooks(c)
    def w(em, res_):
        em.calllog.append(('w', em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    st = obj(c, 0x80, {0x3c: pystub(c, 1, this=True), 0x40: c.emu.stub_fn('recorder', w), 0x6c: pystub(c, 1, this=True)})
    return [rnd(c, 0x130), st]


S(0x4acb30, 'GUESS save_fields', 'thiscall', None, ret='al', gen=_g4acb30, note='batch67553')
