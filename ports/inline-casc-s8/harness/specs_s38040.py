"""specs_s38040.py - cascade s8 batch 38040. Registry object at 0x7003a4 with logging slots 0xc4 (3 args incl. this), 0xac (7 args) and 0x40 (3 args): every call is appended to the call log in order (the generic
recorder only keeps 8 rows), so the argument order, the names and the source fields are all compared. The entity has random fields at +0xc .. +0x30; 0x4690b0 is a hook."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g4ffc30(c):
    clear_hooks(c)
    e = c.emu

    def slot(name, n):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx')) + tuple(em.arg32(i) for i in range(n)))
            em.ret(eax=0, argbytes=4 * n)
        return e.stub_fn(name, h)
    reg = obj(c, 0x100, {0xc4: slot('c4', 2), 0xac: slot('ac', 6), 0x40: slot('40', 2)})
    e.w32(0x7003a4, reg)
    hook_rec(c, 0x4690b0, 0, this=True)
    return [rnd(c, 0x40)]


S(0x4ffc30, 'GUESS register entity script variables', 'thiscall', None, ret=None, gen=_g4ffc30, note='batch38040')
