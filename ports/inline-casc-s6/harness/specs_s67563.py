"""specs_s67563.py - cascade s6 batch 67563 (0x466dc0, thiscall(stream) ret 4, returns al). This slots 0x3d4 / 0x358 (0 args) and 0x3ec (custom stub logging only its first argument: the second is the
caller's leftover esi) exist on the object; 0x463620 (validator) and 0x466eb0 / 0x4946a0 are hooks. The stream object has recorders for slots 0x40 (writes a handle through the pointer, stack-marked, zero
sometimes), 0x48, 0x50, 0x68 (all value-writing stubs log every destination in the call log) and 0x6c (returns a sub-stream with slot 0x50); y has slot 0x1c."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g466dc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hv = r.choice([0, 0, 5, 0x77, 0xffff])
    hook_rec(c, 0x463620, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 1, 0x100]))
    hook_rec(c, 0x466eb0, 2, this=True)
    hook_rec(c, 0x4946a0, 1, this=True)

    def mkw(slot):
        def w(em, res_):
            a = em.arg32(0)
            em.calllog.append(('w', slot, a if 0x20000000 <= a < 0x30000000 else 0x57ac0000))
            if slot == 0x40 and not (0x20000000 <= a < 0x30000000):     # the handle variable on the caller's stack
                em.wbytes(a, hv.to_bytes(4, 'little'))
            em.ret(eax=0, argbytes=4)
        return e.stub_fn('recorder', w)
    sub = obj(c, 0x20, {0x50: pystub(c, 1, this=True)})
    y = obj(c, 0x20, {0x1c: pystub(c, 1, this=True)})

    def s3ec(em, res_):
        em.calllog.append(('3ec', em.arg32(0)))
        em.ret(eax=y, argbytes=8)
    st = obj(c, 0x40, {0x40: mkw(0x40), 0x48: mkw(0x48), 0x50: mkw(0x50), 0x68: mkw(0x68),
                       0x6c: pystub(c, 1, this=True, ret=sub)})
    t = obj(c, 0x200, {0x3d4: pystub(c, 0, this=True), 0x358: pystub(c, 0, this=True), 0x3ec: e.stub_fn('recorder', s3ec)})
    e.w32(t + 0x1ce, rnd(c, 0x10))
    return [t, st]


S(0x466dc0, 'GUESS load_object', 'thiscall', None, ret='al', gen=_g466dc0, note='batch67563')
