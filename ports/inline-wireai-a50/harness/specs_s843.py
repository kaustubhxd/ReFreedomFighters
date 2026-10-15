"""specs_s843.py - area 50, batch 843: ZDamageBox::Init2. The owner's manager list, the global manager, the entry
objects, the centre helper (hooked), the allocator (hooked, cdecl) and the queue virtual are all fake and logged."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, vslot, install_logger
import struct


def _gen(c):
    e, r = c.emu, c.rng
    ids = [r.getrandbits(16) | 1 for _ in range(r.randint(0, 4))]
    st = {'pos': 0}

    def cen(e, res):
        geom, out = e.reg('ecx'), e.arg32(0)
        e.calllog.append(('ZBaseGeom::GetCen', geom))
        for i in range(3):
            e.wf32(out + 4 * i, [0.5, -1.5, 2.25][i])
        e.ret(eax=0, argbytes=4)

    def alloc(e, res):
        sz = e.arg32(0)
        e.calllog.append(('new', sz))
        a = e.alloc(sz, 8)
        e.wbytes(a, bytes(r.getrandbits(8) for _ in range(sz)))   # fresh memory is not zero: the port must write what it needs
        e.ret(eax=a, argbytes=0)

    def m4c(e, res):
        st['pos'] = 0
        e.ret(eax=0, argbytes=4)

    def m5c(e, res):
        p = e.arg32(0)
        more = st['pos'] < len(ids)
        val = ids[st['pos']] if more else 0
        st['pos'] += 1
        e.w32(p, 1 if more else 0)
        e.calllog.append(('mgr.next', val))
        e.ret(eax=val, argbytes=4)

    def gm58(e, res):
        eid = e.arg32(0)
        e.calllog.append(('glob.58', eid))
        e.ret(eax=objs.get(eid, 0), argbytes=4)

    def obj_84(e, res):
        p = e.arg32(0)
        e.calllog.append(('obj.84', struct.unpack('<3I', e.rbytes(p, 12))))
        e.ret(eax=0, argbytes=4)

    def queue(e, res):
        rec = e.arg32(0)
        e.calllog.append(('queue', e.rbytes(rec, 13)))   # whole 13-byte record
        e.ret(eax=0, argbytes=4)

    objs = {}
    only_hooks(c, {0x4daf90: cen, 0x41e290: alloc})
    install_logger(c, nargs=2)
    for eid in ids:
        o = vt_object(c, 0x40, {0x84: obj_84, 0x1e0: vslot('obj.1e0', 1, ret=r.choice([0, 1]))}, nslots=0x200, name='obj')
        e.w32(o + 0x54, r.choice([0, 1, 1]))
        e.w32(o + 8, rnd(c, 0x20))
        objs[eid] = o
    mgr = vt_object(c, 0x40, {0x4c: m4c, 0x5c: m5c}, nslots=0x200, name='mgr')
    gl = vt_object(c, 0x40, {0x58: gm58}, nslots=0x200, name='glob')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, gl)
    e.w32(0x70039c, g)
    queue_obj = vt_object(c, 0x20, {4: queue}, nslots=0x40, name='queueowner')
    self = vt_object(c, 0x100, {0x84: queue}, nslots=0x200, name='damagebox')
    owner = rnd(c, 0x40)
    e.w32(owner + 0x18, mgr)
    e.w32(self + 0x48, owner)
    e.w32(self + 0x84, queue_obj)
    return [self]


S(0x5db2e0, 'ZDamageBox::Init2', 'thiscall', None, gen=_gen, note='area50 batch843')
