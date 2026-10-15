from pilot import S
from recruits_util import obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r = c.rng
    def log(tag):
        return lambda emu, k: emu.calllog.append((tag, emu.reg('ecx'), *(emu.arg32(i) for i in range({
            'self-init': 0, 'self-reset': 2, 'child-clear': 2, 'child-config': 3, 'child-finish': 1
        }[tag]))))
    child = obj(c, 0x20, {
        0x2d0: pystub(c, 2, this=True, pop=8, ret=r.getrandbits(32), side=log('child-clear')),
        0x2f0: pystub(c, 3, this=True, pop=12, ret=r.getrandbits(32), side=log('child-config')),
        0x210: pystub(c, 1, this=True, pop=4, ret=r.getrandbits(32), side=log('child-finish')),
    }, nslots=0x211 // 4)
    self = obj(c, 0x20, {
        0x504: pystub(c, 0, this=True, pop=0, ret=child, side=log('self-init')),
        0x54c: pystub(c, 2, this=True, pop=8, ret=r.getrandbits(32), side=log('self-reset')),
    }, nslots=0x54d // 4)
    return [self]


S(0x473960, 'GUESS initialize and configure nested object', 'thiscall', None,
  ret='eax', gen=gen, note='batch62051')
