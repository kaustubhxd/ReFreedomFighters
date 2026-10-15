from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    def method(tag, ret):
        return pystub(c, 0, this=True, pop=0, ret=ret,
                      side=lambda emu, k: emu.calllog.append((tag, emu.reg('ecx'))))
    self = obj(c, 0x30, {
        0x124: method('self-124', r.getrandbits(32)),
        0xe8: method('self-e8', r.getrandbits(32)),
        0x19c: method('self-19c', r.getrandbits(32)),
    }, nslots=0x19d // 4)
    optional = obj(c, 0x20, {0x18: method('global-3a4', r.getrandbits(32))}) if r.getrandbits(1) else 0
    e.w32(0x7003a4, optional)
    first = obj(c, 0x20, {0x18: method('engine-1aa3', r.getrandbits(32))}) if r.getrandbits(1) else 0
    last_ret = r.getrandbits(32)
    last = obj(c, 0x20, {0x18: method('engine-1a9f', last_ret)}) if r.getrandbits(1) else 0
    engine = sysobj(c)
    e.w32(engine + 0x1aa3, first)
    e.w32(engine + 0x1a9f, last)
    return [self]


S(0x48d060, 'GUESS invoke engine lifecycle callbacks', 'thiscall', None,
  ret='eax', gen=gen, note='batch62058')
