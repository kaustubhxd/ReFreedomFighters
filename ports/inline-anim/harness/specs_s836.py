"""specs_s836.py - animation layer thread, batch 836: ZLNKOBJ::ExecuteCallBack and ZIKLNKOBJ::ForceFacing. The callee
striwcmp, ZBoneAnim::UpdateCallBacks, createmat and vneg are real exe code (their inputs are set up here)."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot, install_crt_str


def _ecb(c):
    install_crt_str(c)
    only_hooks(c, {0x465330: logged_fn('ZBoneAnim::UpdateCallBacks', 1)})
    e, r = c.emu, c.rng
    names = [b'Walk', b'walk_fwd', b'Run', b'UB_Hold']
    n = r.randint(0, 6)
    tab = rnd(c, 0x18 * n + 0x30)
    for i in range(n):
        ent = tab + 0x18 * i
        e.w32(ent + 4, r.choice([0, 1, 1, 3]))
        ba = rnd(c, 0x80)
        e.wbytes(ba + 0x4c, r.choice(names) + b'\0')
        e.w32(ent + 0x14, ba if r.random() < 0.9 else 0)
    o = vt_object(c, 0x200, {}, nslots=0x30, name='lnk')
    e.w32(o + 0x1c, tab)
    e.w32(o + 0x20, n)
    nm = e.alloc(0x20, 4)
    e.wbytes(nm, r.choice(names) + b'\0')
    return [o, nm]


def _ff(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    install_fmod(c) if False else None
    mat_callee = [0]

    def tgt(e, res):
        p = e.arg32(0)
        for i in range(3):
            e.wf32(p + 4 * i, [1.5, 0.0, -2.0][i] + r.uniform(-0.1, 0.1))
        e.calllog.append(('vt84',))
        e.ret(eax=0, argbytes=4)
    import struct

    def mat370(e, res):
        m, t = e.arg32(0), e.arg32(1)
        # the two pointers are locals: compare what they point to, not the addresses
        e.calllog.append(('vt370', struct.unpack('<9I', e.rbytes(m, 36)), struct.unpack('<3I', e.rbytes(t, 12))))
        e.ret(eax=0, argbytes=8)
    o = vt_object(c, 0x200, {0x84: tgt, 0x370: mat370}, nslots=0x130, name='lnk')
    dir_ = rnd(c, 0x20)
    for i in range(3):
        e.wf32(dir_ + 4 * i, c.fv(-3, 3))
    return [o, dir_]


S(0x462a70, 'ZLNKOBJ::ExecuteCallBack', 'thiscall', None, gen=_ecb, note='batch836')
S(0x466640, 'ZIKLNKOBJ::ForceFacing', 'thiscall', None, gen=_ff, note='batch836')
