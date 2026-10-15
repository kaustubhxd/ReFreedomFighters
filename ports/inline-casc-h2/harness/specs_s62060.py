from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    logs = []
    def msg_stub(tag):
        def record(emu, k):
            logs.append((tag, *(emu.arg32(i) for i in range(5))))
        return pystub(c, 5, pop=0, side=record)
    m1 = obj(c, 0x40, {0x2c: msg_stub('first')})
    m2 = obj(c, 0x40, {0x2c: msg_stub('second')})
    gets = [m1, m2]
    def getmsg(emu, k):
        args = (emu.arg32(0), emu.arg32(1))
        tag, msg = (('line172', gets[0]), ('line173', gets[1]))[len([x for x in emu.calllog if x[0] == 'getmsg'])]
        emu.calllog.append(('getmsg', tag, *args))
        emu.ret(eax=msg, argbytes=8)
    lg = obj(c, 0x30, {0x20: e.stub_fn('get logger message', getmsg)})
    e.w32(0x700390, lg)
    self = rnd(c, 0x12140)
    for off in (0xd628, 0xd62c, 0x12130, 0x12134):
        e.w32(self + off, r.getrandbits(32))
    return [self]


S(0x4d0c00, 'GUESS log paired object diagnostics', 'thiscall', None,
  ret=None, gen=gen, note='batch62060')
