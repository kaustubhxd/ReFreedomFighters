"""specs_s5824.py - unclaimed-57, batch 124: 0x5c3c60 (COpenWindow::TimeUpdate, GUESS name), thiscall, no args, plain ret. The sub-object (engine +0x9b) has slot
+0x138 (returns object X), slot +0x58 (one arg, logged; the first call returns S, the second S2 (0 in about one case in six)). X has slot +0x88 (two args, logged; writes
a per-key dword through the pointer). S has slot +0x84 (one arg; logs the 12 bytes at the pointer) and a block at +8 whose dwords +0x30..+0x38 are random. The object
M at this+0x44 has slot +0x8c (one arg, logs 12 bytes) and slot +0x180 (two args, logs 12 bytes and the float bits; returns a per-case flag). S2 has slot +0x2c4
(returns T); T has slot +0x2fc (one arg, logged). The logger (global 0x700390) has slot +0x20 (two args: returns O) and O has slot +0x2c (cdecl, logged). this+0x48
is a byte (0 in about half the cases) and this+0x49 a random dword. The stack addresses are logged as byte contents only."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5c60(c):
    e = c.emu
    rnd = c.rng
    key_v = rnd.getrandbits(32)
    flag180 = rnd.choice([0, 1])
    k58 = [0]
    S2_null = rnd.random() < 0.17
    r_2c4 = None
    sub_ret = [None, None]

    def h138(em, r):
        em.calllog.append(('138', 0, None, ()))
        em.ret(eax=X_obj, argbytes=0)

    def h58(em, r):
        i = k58[0]
        k58[0] += 1
        em.calllog.append(('58', i, None, (em.arg32(0),)))
        em.ret(eax=(S_obj if i == 0 else (0 if S2_null else S2_obj)), argbytes=4)

    def h88(em, r):
        k = em.arg32(0)
        em.calllog.append(('88', 0, None, (k,)))
        em.w32(em.arg32(1), key_v if k == 0x681320 else 0)
        em.ret(eax=0, argbytes=8)

    def h84(em, r):
        em.calllog.append(('84', 0, None, (em.rbytes(em.arg32(0), 12),)))
        em.ret(eax=0, argbytes=4)

    def h8c(em, r):
        em.calllog.append(('8c', 0, None, (em.rbytes(em.arg32(0), 12),)))
        em.ret(eax=0, argbytes=4)

    def h180(em, r):
        em.calllog.append(('180', 0, None, (em.rbytes(em.arg32(0), 12), em.arg32(1))))
        em.ret(eax=flag180, argbytes=8)

    def h2c4(em, r):
        em.calllog.append(('2c4', 0, None, ()))
        em.ret(eax=T_obj, argbytes=0)

    def h2fc(em, r):
        em.calllog.append(('2fc', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h20(em, r):
        em.calllog.append(('lg20', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=O_obj, argbytes=8)

    def h2c(em, r):
        em.calllog.append(('O2c', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    vt_sub = e.fake_vtable('d5c60_sub', 200, {0x138: h138, 0x58: h58})
    vt_X = e.fake_vtable('d5c60_X', 200, {0x88: h88})
    vt_S = e.fake_vtable('d5c60_S', 200, {0x84: h84})
    vt_M = e.fake_vtable('d5c60_M', 200, {0x8c: h8c, 0x180: h180})
    vt_S2 = e.fake_vtable('d5c60_S2', 200, {0x2c4: h2c4})
    vt_T = e.fake_vtable('d5c60_T', 200, {0x2fc: h2fc})
    vt_lg = e.fake_vtable('d5c60_lg', 100, {0x20: h20})
    vt_O = e.fake_vtable('d5c60_O', 60, {0x2c: h2c})
    X_obj = _rnd(c, 0x40)
    e.w32(X_obj, vt_X)
    S_obj = _rnd(c, 0x40)
    e.w32(S_obj, vt_S)
    g = _rnd(c, 0x80)
    for k in (0x30, 0x34, 0x38):
        e.w32(g + k, rnd.getrandbits(32))
    e.w32(S_obj + 8, g)
    S2_obj = _rnd(c, 0x40)
    e.w32(S2_obj, vt_S2)
    T_obj = _rnd(c, 0x40)
    e.w32(T_obj, vt_T)
    O_obj = _rnd(c, 0x40)
    e.w32(O_obj, vt_O)
    M = _rnd(c, 0x40)
    e.w32(M, vt_M)
    lg = _rnd(c, 0x40)
    e.w32(lg, vt_lg)
    e.w32(0x700390, lg)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x44, M)
    e.wbytes(self_obj + 0x48, bytes([0 if rnd.random() < 0.5 else rnd.getrandbits(8)]))
    e.w32(self_obj + 0x49, rnd.getrandbits(32))
    return [self_obj]


S(0x5c3c60, 'COpenWindow::TimeUpdate (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5c60,
  note='unclaimed-57 batch 124; GetCen (batch411) inlined; sub slots +0x138 and +0x58; X, S, S2, T, M, O and logger fake')
