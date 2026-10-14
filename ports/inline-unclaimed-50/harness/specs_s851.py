"""specs_s851.py - area 50, batch 851: ZFFHERO::Load(ZLoadGame*) (0x592d50), thiscall, callee pops 4, bool result.
Stand-ins (hooked, logged): the base load 0x483f20, the object 0x4cc1d0, the sub-loads 0x58a8d0 / 0x58a9b0 (fastcall) and
0x59d3a0. The load object's slots write values from a list fixed at generation time; each slot returns the load object
(the exe chains on those returns). Dword reads through 0x48 are kept small: they are table indices (+0x684, the record
index), and the global table at 0x7003b8 is a 0x6000-byte buffer. The manager's slot 0x58 maps a key to key*3+1."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    words = [r.getrandbits(32) for _ in range(512)]
    floats = [fin(c.fv(-4, 4)) for _ in range(512)]
    st = {'w': 0, 'f': 0, 'obj': 0}

    def nw():
        v = words[st['w'] % len(words)]
        st['w'] += 1
        return v

    def nf():
        v = floats[st['f'] % len(floats)]
        st['f'] += 1
        return v

    def rd(name, kind):
        def h(e, rr):
            p = e.arg32(0)
            if kind == 'f':
                e.wf32(p, nf())
            elif kind == 'd':
                e.w32(p, nw())
            elif kind == 'i':                      # table index: small
                e.w32(p, nw() % 16)
            elif kind == 'b':
                e.w8(p, nw() & 0xff)
            elif kind == 'v12':
                for i in range(3):
                    e.wf32(p + 4 * i, nf())
            elif kind == 'm48':
                for i in range(12):
                    e.wf32(p + 4 * i, nf())
            e.calllog.append((name, kind))
            e.ret(eax=st['obj'], argbytes=4)
        return h

    def call_obj(name):
        def h(e, rr):
            e.calllog.append((name, e.arg32(0)))
            e.ret(eax=0, argbytes=4)
        return h

    ls = vt_object(c, 0x40, {
        0x40: rd('ls.40', 'd'), 0x48: rd('ls.48', 'i'), 0x50: rd('ls.50', 'f'), 0x58: rd('ls.58', 'd'),
        0x64: call_obj('ls.64'), 0x68: rd('ls.68', 'b'), 0x6c: rd('ls.6c', 'v12'), 0x74: rd('ls.74', 'm48'),
    }, nslots=0x100, name='loadgame')
    st['obj'] = ls

    def base(e, rr):
        e.calllog.append(('base.483f20', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    obj_val = r.getrandbits(32)

    def obj4c(e, rr):
        e.calllog.append(('obj.4cc1d0', e.reg('ecx')))
        e.ret(eax=obj_val, argbytes=0)

    def sub58a8(e, rr):
        e.calllog.append(('sub.58a8d0', e.reg('ecx'), e.reg('edx')))
        e.ret(eax=0, argbytes=0)

    def sub58a9(e, rr):
        e.calllog.append(('sub.58a9b0', e.reg('ecx'), e.reg('edx')))
        e.ret(eax=0, argbytes=0)

    def sub59d3(e, rr):
        e.calllog.append(('sub.59d3a0', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def mgr58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k))
        e.ret(eax=(k * 3 + 1) & 0xffffffff, argbytes=4)

    only_hooks(c, {0x483f20: base, 0x4cc1d0: obj4c, 0x58a8d0: sub58a8, 0x58a9b0: sub58a9, 0x59d3a0: sub59d3})
    mgr = vt_object(c, 0x40, {0x58: mgr58}, nslots=0x60, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    table = rnd(c, 0x6000)
    e.w32(0x7003b8, table)

    self = vt_object(c, 0x1000, {}, nslots=0x20, name='hero')
    sub = rnd(c, 0x80)
    e.w32(self + 0x54, sub)
    return [self, ls]


S(0x592d50, 'ZFFHERO::Load', 'thiscall', None, ret='al', gen=_gen, note='area50 batch851')
