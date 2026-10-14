"""specs_s849.py - area 50, batch 849: ZCar::Load(ZLoadGame*) (0x517f20), a bool result (ret='al').
ZVehicle::Load (0x5159b0, vehicles area) and the undercarriage load (0x525bc0) are stood in: both are hooked and logged.
The load object's slots (0x6c, 0x50, 0x18, 0x68, 0x40, 0x48) write values from a list fixed at generation time; the
render manager (+0x9b, slot 0x138 -> object, its slot 0x88 writes an id, slot 0x58 resolves it) is fake and logged."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0   # finite, so the int() below is safe
    vals = [fin(c.fv(-4, 4)) for _ in range(256)]      # values handed out by the load object, in call order
    st = {'i': 0}

    def nxt():
        v = vals[st['i'] % len(vals)]
        st['i'] += 1
        return v

    def rd_vec(e, rr):
        p = e.arg32(0)
        for i in range(3):
            e.wf32(p + 4 * i, nxt())
        e.calllog.append(('ls.6c', p))
        e.ret(eax=0, argbytes=4)

    def rd_float(e, rr):
        p = e.arg32(0)
        e.wf32(p, nxt())
        e.calllog.append(('ls.50', p))
        e.ret(eax=0, argbytes=4)

    def rd_block(e, rr):
        p, n = e.arg32(0), e.arg32(1)
        for i in range(n):
            e.w8(p + i, (int(abs(nxt()) * 97) + i) & 0xff)
        e.calllog.append(('ls.18', p, n))
        e.ret(eax=0, argbytes=8)

    def rd_byte(e, rr):
        p = e.arg32(0)
        e.w8(p, (int(abs(nxt()) * 97)) & 0xff)
        e.calllog.append(('ls.68', p))
        e.ret(eax=0, argbytes=4)

    def rd_dword(e, rr):
        p = e.arg32(0)
        e.w32(p, int(abs(nxt()) * 1e6) & 0xffffffff)
        e.calllog.append(('ls.40', p))
        e.ret(eax=0, argbytes=4)

    def rd_dword48(e, rr):
        p = e.arg32(0)
        e.w32(p, (int(abs(nxt()) * 1e6) ^ 0x5a5a) & 0xffffffff)
        e.calllog.append(('ls.48', p))
        e.ret(eax=0, argbytes=4)

    ls = vt_object(c, 0x40, {0x6c: rd_vec, 0x50: rd_float, 0x18: rd_block, 0x68: rd_byte,
                             0x40: rd_dword, 0x48: rd_dword48}, nslots=0x80, name='loadgame')

    ok = r.random() < 0.8

    def vehicle_load(e, rr):
        e.calllog.append(('ZVehicle::Load', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=1 if ok else 0, argbytes=4)

    def undercarriage(e, rr):
        e.calllog.append(('undercarriage.load', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    tmp_id = r.getrandbits(32)
    res = r.getrandbits(32)

    def x88(e, rr):
        p = e.arg32(1)
        e.w32(p, tmp_id)
        e.calllog.append(('script.88', e.arg32(0)))
        e.ret(eax=0, argbytes=8)

    def mgr58(e, rr):
        e.calllog.append(('mgr.58', e.arg32(0)))
        e.ret(eax=res, argbytes=4)

    def mgr138(e, rr):
        e.calllog.append(('mgr.138',))
        e.ret(eax=X, argbytes=0)

    only_hooks(c, {0x5159b0: vehicle_load, 0x525bc0: undercarriage})
    X = vt_object(c, 0x40, {0x88: x88}, nslots=0x100, name='script')
    mgr = vt_object(c, 0x40, {0x58: mgr58, 0x138: mgr138}, nslots=0x140, name='render')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)

    self = vt_object(c, 0x1800, {}, nslots=0x20, name='car')
    e.w32(self + 0x164a, r.getrandbits(32))
    return [self, ls]


S(0x517f20, 'ZCar::Load', 'thiscall', None, ret='al', gen=_gen, note='area50 batch849')
