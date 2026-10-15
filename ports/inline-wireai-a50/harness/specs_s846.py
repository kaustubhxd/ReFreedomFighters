"""specs_s846.py - area 50, batch 846: ZDamageBox2::FrameUpdate. Centre helper hooked; the manager (0x58 lookup, 0x114
render slot with six words) and the entries are fake and logged; floats are set so the timers cross their limits."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot, install_logger


def _gen(c):
    e, r = c.emu, c.rng
    def cen(e, rr):
        geom, out = e.reg('ecx'), e.arg32(0)   # out is a local: write the centre, log the geometry only
        e.calllog.append(('ZBaseGeom::GetCen', geom))
        for i in range(3):
            e.wf32(out + 4 * i, [2.0, -3.5, 0.25][i])
        e.ret(eax=0, argbytes=4)
    only_hooks(c, {0x4daf90: cen})
    install_logger(c, nargs=2)
    ids = [r.getrandbits(32) | 1 for _ in range(r.randint(0, 3))]
    st = {'pos': 0}
    entries = {}

    def m4c(e, rr):
        st['pos'] = 0
        e.ret(eax=0, argbytes=4)

    def m5c(e, rr):
        p = e.arg32(0)
        more = st['pos'] < len(ids)
        val = ids[st['pos']] if more else 0
        st['pos'] += 1
        e.w32(p, 1 if more else 0)
        e.calllog.append(('owner.next', val))
        e.ret(eax=val, argbytes=4)

    def glob58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('glob.58', k))
        e.ret(eax=entries.get(k, 0), argbytes=4)

    def m114(e, rr):
        args = tuple(e.arg32(k) for k in range(6))
        e.calllog.append(('mgr.114', args[1], args[3], args[5]))
        e.ret(eax=r.getrandbits(32), argbytes=24)

    def ent84(e, rr):
        p = e.arg32(0)
        e.calllog.append(('ent.84', [round(e.rf32(p + 4 * i), 5) for i in range(3)]))
        e.ret(eax=0, argbytes=4)

    def ent128(e, rr):
        e.calllog.append(('ent.128', e.arg32(0)))   # the exe passes the 16-bit id (movzx), so the full word is logged
        e.ret(eax=0, argbytes=4)

    def a8c(e, rr):
        e.calllog.append(('A.8c',))
        e.ret(eax=0, argbytes=4)

    def a180(e, rr):
        p, f = e.arg32(0), e.arg32(1)
        e.calllog.append(('A.180', round(e.argf(1), 4)))
        e.ret(eax=r.choice([0, 1]), argbytes=8)

    for eid in ids:
        ent = vt_object(c, 0x40, {0x84: ent84, 0x128: ent128}, nslots=0x60, name='entry')
        e.w32(ent + 8, rnd(c, 0x20))
        entries[eid] = ent
    mgr = vt_object(c, 0x40, {0x4c: m4c, 0x5c: m5c, 0x58: glob58, 0x114: m114}, nslots=0x60, name='owner')
    gl = vt_object(c, 0x40, {0x58: glob58, 0x114: m114}, nslots=0x60, name='glob')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, gl)
    e.wf32(g + 0x48, r.choice([0.016, 0.5, c.fv(0, 2)]))
    e.w32(0x70039c, g)
    A = vt_object(c, 0x40, {0x8c: a8c, 0x180: a180}, nslots=0x100, name='A')
    self = vt_object(c, 0x200, {}, nslots=0x20, name='damagebox2')
    e.w8(self + 0x54, r.choice([0, 1, 1]))
    owner = rnd(c, 0x40)
    e.w32(owner, 0)
    e.w32(self + 0x48, mgr)
    e.w32(self + 0x44, A)
    for off in (0x50, 0x87, 0x8b, 0x8f, 0x93, 0x97, 0x9b):
        e.wf32(self + off, r.choice([c.fv(-1, 1), c.fv(0, 3), 0.0]))
    e.wf32(self + 0x97, r.choice([0.5, 1.0, c.fv(0.1, 2)]))
    if r.random() < 0.3:   # exact equality of the 0x8f timer and the 0x87 limit (for the > versus >= boundary)
        import struct
        dt = struct.unpack('<f', e.rbytes(g + 0x48, 4))[0]
        z = struct.unpack('<f', e.rbytes(self + 0x8f, 4))[0]
        e.wf32(self + 0x87, struct.unpack('<f', struct.pack('<f', dt + z))[0])
    e.w32(self + 0x7f, r.getrandbits(32))
    e.w32(self + 0x93, r.getrandbits(32))
    return [self]


S(0x5dba60, 'ZDamageBox2::FrameUpdate', 'thiscall', None, gen=_gen, note='area50 batch846')
