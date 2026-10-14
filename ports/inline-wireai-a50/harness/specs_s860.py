"""specs_s860.py - area 50, batch 860: 0x439fd0 (name GUESS), thiscall, one stack arg (a source record), ret 4.
Stand-ins (hooked, logged): the base steps 0x4388a0 and 0x438910, the value step 0x4386a0, the constructor 0x4ccbe0 (returns
its object), and the allocator 0x41e290 (cdecl; a fresh block, or 0). The logger (0x700390) and its sink (vt +0x2c, cdecl)
are fake and logged. The object's vt +0x08 is logged. The source record has the sentinels -1 and zero words in varied
combinations, so both branches of the flag test run."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    def log(name, nargs=0):
        def h(e, rr):
            e.calllog.append((name, e.reg('ecx')) + tuple(e.arg32(k) for k in range(nargs)))
            e.ret(eax=0, argbytes=4 * nargs)
        return h

    def ctor(e, rr):
        this, a, b = e.reg('ecx'), e.arg32(0), e.arg32(1)
        e.calllog.append(('ctor.4ccbe0', a, b))
        e.ret(eax=this, argbytes=8)

    def value(e, rr):
        this, a, b = e.reg('ecx'), e.arg32(0), e.arg32(1)
        e.calllog.append(('value.4386a0', a, b))
        e.ret(eax=0, argbytes=8)

    alloc_ok = r.random() < 0.8

    def newf(e, rr):
        n = e.arg32(0)
        e.calllog.append(('new', n))
        e.ret(eax=e.alloc(n, 8) if alloc_ok else 0, argbytes=0)

    def sink_print(e, rr):
        e.calllog.append(('sink.2c', e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    def logger_where(e, rr):
        e.calllog.append(('log.where', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    only_hooks(c, {0x4388a0: log('base.4388a0'), 0x438910: log('base.438910'),
                   0x4386a0: value, 0x4ccbe0: ctor, 0x41e290: newf})
    sink = e.fake_object('sink', 0x10, nslots=0x20, slots={0x2c: sink_print})
    logger = e.fake_object('logger', 0x10, nslots=9, slots={0x20: logger_where})
    e.w32(0x700390, logger)
    self = vt_object(c, 0x100, {0x8: log('self.8', 2)}, nslots=0x20, name='self')
    src = rnd(c, 0x100)
    sentinel = lambda: 0xffffffff if r.random() < 0.6 else r.getrandbits(32)
    e.w32(src + 0x80, sentinel())
    e.w32(src + 0x90, sentinel())
    e.w8(src + 0xa0, r.choice([0, 1]))
    e.w32(src + 0xa7, r.choice([0, 0, 0x1234, 0x5678]))
    e.w32(src + 0xab, r.choice([0, 0, 0x9abc]))
    return [self, src]


S(0x439fd0, 'Fn439fd0 (GUESS name)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch860')
