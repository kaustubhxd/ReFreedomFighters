"""specs_s838.py - area 50, batch 838: ZLNKOBJ::UpdateAnimSound. GetMatPos (0x4db2c0) is hooked with a deterministic
matrix/position per geometry; the sound manager, the sound objects and the object's virtuals are fake logged objects."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, vslot, install_logger


def _gmp(e, res):
    geom, m, p = e.reg('ecx'), e.arg32(0), e.arg32(1)
    e.calllog.append(('ZBaseGeom::GetMatPos', geom))
    import random
    rr = random.Random(geom & 0xffff)
    for i in range(9):
        e.wf32(m + 4 * i, rr.uniform(-1, 1))
    for i in range(3):
        e.wf32(p + 4 * i, rr.uniform(-20, 20))
    e.ret(eax=0, argbytes=8)


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x4db2c0: _gmp})
    install_logger(c, nargs=2)
    snds = {}

    import struct

    def setpos(e, res):
        m, p = e.arg32(0), e.arg32(1)   # locals: log what they hold, not their addresses
        e.calllog.append(('snd.SetPos', struct.unpack('<9I', e.rbytes(m, 36)), struct.unpack('<3I', e.rbytes(p, 12))))
        e.ret(eax=0, argbytes=8)

    def sound_obj(i):
        geomobj = rnd(c, 0x20)
        s = vt_object(c, 0x40, {0x7c: setpos}, nslots=0x20, name='snd%d' % i)
        e.w32(s + 8, geomobj)
        return s

    def get_snd(e, res):
        sid = e.arg32(0)
        e.calllog.append(('mgr.GetSound', sid))
        e.ret(eax=snds.get(sid, 0), argbytes=4)
    mgr = vt_object(c, 0x40, {0x58: get_snd}, nslots=0x30, name='mgr')
    for k in range(r.randint(0, 3)):
        sid = r.choice([r.randint(1, 9), r.getrandbits(32)])
        snds[sid] = sound_obj(k) if r.random() < 0.8 else 0
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    ret20 = rnd(c, 0x20)
    e.w32(ret20 + 8, rnd(c, 0x20))
    o = vt_object(c, 0x200, {0x20: vslot('self.vt20', 0, ret=ret20)}, nslots=0x100, name='self')
    ids = [sid if r.random() < 0.7 else 0 for sid in list(snds.keys())[:3]]
    while len(ids) < 3:
        ids.append(0)
    e.w32(o + 0x12a, ids[0])
    e.w32(o + 0x12e, ids[1])
    e.w32(o + 0x132, ids[2])
    e.wf32(o + 0x48, c.fv(-5, 5)); e.wf32(o + 0x4c, c.fv(-5, 5)); e.wf32(o + 0x50, c.fv(-5, 5))
    for i in range(9):
        e.wf32(o + 0x24 + 4 * i, c.fv(-1, 1))
    return [o]


S(0x464f50, 'ZLNKOBJ::UpdateAnimSound', 'thiscall', None, gen=_gen, note='area50 batch838')
