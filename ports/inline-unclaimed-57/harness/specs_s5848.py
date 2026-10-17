"""specs_s5848.py - 0x5c6770 (ZFFSearchLightGroup::FrameUpdate). Thiscall, no args, ret void.
Self object: +0x48 list head, +0x60 object with vtable, +0x64 counter, +0x6d float.
Result X from slot 0x30: +0x1c ptr (bit 10 test), +0x4 vtable, +0x20 ptr or 0, +0x24 float.
Hooked callees: 0x5c6640, 0x5c74a0 (ret al=skip_flag), 0x5c7a40, 0x5c7980, 0x5c7a00, 0x443ef0, 0x5c7160.
Vtable slots: 0x30 (ret X or 0), 0x14 (ret counter), 0x80 (vector), 0x4c/0x5c (list), 0x1e0/0x438 (flags), 0x3c, 0x210, 0x58."""
from pilot import S, F
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5c6770(c):
    e = c.emu
    rnd = c.rng

    # Allocate main objects - larger sizes to ensure all field accesses are safe
    self_obj = _rnd(c, 0x200)
    obj60 = _rnd(c, 0x200)
    X = _rnd(c, 0x200)
    X_1c = _rnd(c, 0x200)
    engine_global = _rnd(c, 0x400)
    engine_sub = _rnd(c, 0x400)
    list_head = _rnd(c, 0x200)
    list_item = _rnd(c, 0x200)

    # Hooked external callees
    def h_5c6640(em, r):
        em.calllog.append(('5c6640', None, None, ()))
        em.ret(eax=0, argbytes=0)

    def h_5c74a0(em, r):
        skip = rnd.randint(0, 1)
        em.calllog.append(('5c74a0', skip, None, ()))
        em.ret(eax=skip, argbytes=4)

    def h_5c7a40(em, r):
        em.calllog.append(('5c7a40', None, None, ()))
        em.ret(eax=0, argbytes=4)

    def h_5c7980(em, r):
        em.calllog.append(('5c7980', None, None, ()))
        em.ret(eax=0, argbytes=0)

    def h_5c7a00(em, r):
        em.calllog.append(('5c7a00', None, None, ()))
        em.ret(eax=0, argbytes=4)

    def h_443ef0(em, r):
        em.calllog.append(('443ef0', None, None, ()))
        em.ret(eax=0, argbytes=8)

    def h_5c7160(em, r):
        em.calllog.append(('5c7160', None, None, ()))
        em.ret(eax=rnd.randint(0, 1), argbytes=8)

    # Vtable slot handlers
    def h_slot_30(em, r):
        arg = em.arg32(0)
        result = X if rnd.random() < 0.7 else 0
        em.calllog.append(('slot_30', arg, None, ()))
        em.ret(eax=result, argbytes=4)

    def h_slot_14_obj60(em, r):
        count = em.r32(self_obj + 0x64)
        em.calllog.append(('slot_14_obj60', count, None, ()))
        em.ret(eax=count, argbytes=0)

    def h_slot_14_X4(em, r):
        em.calllog.append(('slot_14_X4', None, None, ()))
        em.ret(eax=rnd.randint(0, 1), argbytes=0)

    def h_slot_80(em, r):
        ptr1 = em.arg32(0)
        ptr2 = em.arg32(1)
        em.calllog.append(('slot_80', ptr1, ptr2, ()))
        em.ret(eax=0, argbytes=8)

    def h_slot_4c(em, r):
        ptr = em.arg32(0)
        em.calllog.append(('slot_4c', ptr, None, ()))
        em.ret(eax=0, argbytes=4)

    def h_slot_5c(em, r):
        ptr = em.arg32(0)
        result = list_item
        em.calllog.append(('slot_5c', ptr, result, ()))
        em.ret(eax=result, argbytes=4)

    def h_slot_1e0(em, r):
        arg = em.arg32(0)
        em.calllog.append(('slot_1e0', arg, None, ()))
        em.ret(eax=rnd.randint(0, 1), argbytes=4)

    def h_slot_438(em, r):
        em.calllog.append(('slot_438', None, None, ()))
        em.ret(eax=rnd.randint(0, 1), argbytes=0)

    def h_slot_3c(em, r):
        arg = em.arg32(0)
        em.calllog.append(('slot_3c', arg, None, ()))
        em.ret(eax=0, argbytes=4)

    def h_slot_210(em, r):
        arg = em.arg32(0)
        em.calllog.append(('slot_210', arg, None, ()))
        em.ret(eax=0, argbytes=4)

    def h_slot_58(em, r):
        arg = em.arg32(0)
        result = _rnd(c, 0x40) if rnd.random() < 0.5 else 0
        em.calllog.append(('slot_58', arg, result, ()))
        em.ret(eax=result, argbytes=4)

    def h_slot_84(em, r):
        ptr = em.arg32(0)
        em.calllog.append(('slot_84', ptr, None, ()))
        em.ret(eax=0, argbytes=4)

    def h_slot_3a0(em, r):
        result = _rnd(c, 0x100) if rnd.random() < 0.5 else 0
        em.calllog.append(('slot_3a0', None, result, ()))
        em.ret(eax=result, argbytes=0)

    def h_slot_398(em, r):
        arg = em.arg32(0)
        em.calllog.append(('slot_398', arg, None, ()))
        em.ret(eax=0, argbytes=4)

    def h_slot_84(em, r):
        ptr = em.arg32(0)
        em.calllog.append(('slot_84', ptr, None, ()))
        em.ret(eax=0, argbytes=4)

    def h_slot_4_on_result(em, r):
        arg = em.arg32(0)
        em.calllog.append(('slot_4_on_result', arg, None, ()))
        em.ret(eax=0, argbytes=4)

    # Register external hooked callees
    e.hook(0x5c6640, h_5c6640)
    e.hook(0x5c74a0, h_5c74a0)
    e.hook(0x5c7a40, h_5c7a40)
    e.hook(0x5c7980, h_5c7980)
    e.hook(0x5c7a00, h_5c7a00)
    e.hook(0x443ef0, h_443ef0)
    e.hook(0x5c7160, h_5c7160)

    # Create vtable for obj60 (at self+0x60)
    vt_obj60 = e.fake_vtable('obj60', 600, {
        0x30: h_slot_30,
        0x14: h_slot_14_obj60,
    })
    e.w32(obj60, vt_obj60)

    # Setup self object
    e.w32(self_obj + 0x60, obj60)
    # self+0x64 is a counter, but the code dereferences it with slot_30, so keep it 0-10 as is
    counter_val = rnd.randint(0, 10)
    e.w32(self_obj + 0x64, counter_val)
    e.w32(self_obj + 0x48, list_head)
    e.wbytes(self_obj + 0x6d, struct.pack('<f', rnd.random() * 100))

    # Create vtable for X (result object)
    vt_X = e.fake_vtable('X', 600, {
        0x210: h_slot_210,
    })
    e.w32(X, vt_X)

    # Setup X object
    e.w32(X + 0x1c, X_1c)
    bit_field = rnd.randint(0, 0x1000000)
    e.w32(X_1c + 0x3c, bit_field)
    e.w32(X + 0x20, _rnd(c, 0x40) if rnd.random() < 0.5 else 0)
    e.wbytes(X + 0x24, struct.pack('<f', rnd.random() * 100))
    e.wbytes(X + 0x18, struct.pack('<f', rnd.random() * 10))

    # Create vtable for X+4
    vt_X4 = e.fake_vtable('X_4', 600, {
        0x14: h_slot_14_X4,
        0x3c: h_slot_3c,
    })
    e.w32(X + 4, vt_X4)

    # Create vtable for X->+0x1c
    vt_X_1c = e.fake_vtable('X_1c', 600, {
        0x80: h_slot_80,
        0x84: h_slot_84,
    })
    e.w32(X_1c, vt_X_1c)

    # Setup list head
    e.w32(list_head + 0x18, list_item if rnd.random() < 0.5 else 0)

    # Create vtable for list items
    vt_list = e.fake_vtable('list_item', 1000, {
        0x4c: h_slot_4c,
        0x5c: h_slot_5c,
        0x1e0: h_slot_1e0,
        0x438: h_slot_438,
        0x3a0: h_slot_3a0,
        0x398: h_slot_398,
    })
    e.w32(list_item, vt_list)
    e.w32(list_item + 0x18, list_item if rnd.random() < 0.2 else 0)

    # Create vtable for engine_sub
    vt_engine_sub = e.fake_vtable('engine_sub', 600, {
        0x58: h_slot_58,
        0x1e0: h_slot_1e0,
        0x438: h_slot_438,
    })
    e.w32(engine_sub, vt_engine_sub)

    return [self_obj]


S(0x5c6770, 'ZFFSearchLightGroup::FrameUpdate thiscall', 'thiscall', None, ret=None, gen=_d5c6770,
  note='complex linked-list traversal with vtable slots; hooked 0x5c6640, 0x5c74a0, 0x5c7a40, 0x5c7980, 0x5c7a00, 0x443ef0, 0x5c7160')
