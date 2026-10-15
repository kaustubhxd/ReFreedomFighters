from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    def rec(tag, n, pop, ret=0):
        return pystub(c, n, this=True, pop=pop, ret=ret,
            side=lambda emu, k: emu.calllog.append((tag, emu.reg('ecx'), emu.reg('edx'), *(emu.arg32(i) for i in range(n)))))
    result1, result2 = rnd(c, 0x40), rnd(c, 0x40)
    vt1 = obj(c, 0x360, {0x2ec: rec('second-dispatch', 1, 4)})
    vt2 = obj(c, 0x360, {0x34c: rec('final', 5, 20)})
    e.w32(result1, e.r32(vt1))
    e.w32(result2, e.r32(vt2))
    access_count = [0]
    def access(emu, k):
        idx = access_count[0]; access_count[0] += 1
        emu.calllog.append(('access', emu.reg('ecx'), idx))
        emu.ret(eax=(result1 if idx == 0 else result2))
    access_fn = e.stub_fn('accessor', access)
    first = rec('first-dispatch', 1, 4)
    self = obj(c, 0x100, {0x2ec: first, 0x2c4: access_fn})
    e.w32(self + 0x70, r.choice([0x20, 0, 0x21]))
    e.w32(self + 0x8f, r.choice([0, 1, 2]))
    return [self, r.getrandbits(32)]


S(0x4f4d80, 'GUESS staged virtual dispatch', 'thiscall', None,
  ret=None, gen=gen, note='batch62078')
